/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:51:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/15 20:07:32 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	check_death(t_god *info, t_philo *philo);
static void	end_threads(t_god *info, t_philo *philo);

/*----------- 1.Create and start threads ---------------*/
int	start_threads(t_god *info)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = info->philo;
	info->start_proc = timestamp();
	while (i < info->nb_philo)
	{
		if (pthread_create(&(p[i].thread_id), NULL, &routine, &(p[i])))
			return (ERROR);
		pthread_mutex_lock(&(info->check_meal));
		p[i].last_time_eat = timestamp();
		pthread_mutex_unlock(&(info->check_meal));
		i++;
	}
	check_death(info, info->philo);
	end_threads(info, p);
	return (0);
}

/*----------- 2.Check if philo dying ---------------*/
static void	check_death(t_god *info, t_philo *philo)
{
	int	i;

	while (!info->all_philo_eaten)
	{
		i = -1;
		while (++i < info->nb_philo && !(info->dead))
		{
			pthread_mutex_lock(&info->check_meal);
			if (passing_time(philo[i].last_time_eat,
					timestamp()) > info->time_death)
			{
				print_action(info, philo[i].philo_id, ""RED"died"RESET"");
				info->dead = 1;
			}
			pthread_mutex_unlock(&info->check_meal);
			usleep(10);
		}
		if (info->dead)
			break ;
		i = 0;
		pthread_mutex_lock(&info->check_meal);
		while (info->x_meal != -1 && i < info->nb_philo
			&& philo[i++].x_eat >= info->x_meal);
		if (i == info->nb_philo)
			info->all_philo_eaten = 1;
		pthread_mutex_unlock(&info->check_meal);
	}
}

/*----------- 3.Destroy mutex and threads ---------------*/
static void	end_threads(t_god *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		pthread_mutex_destroy(&(info->fork[i++]));
	}
	pthread_mutex_destroy(&(info->write));
	pthread_mutex_destroy(&(info->check_meal));
}

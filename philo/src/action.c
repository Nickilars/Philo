/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:14:16 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/15 20:00:38 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	if_one_philo(t_god *info);
void		sleep_philo(long long time, t_god *info);

/*----------- 1.Eat ---------------*/
void	eat_philo(t_philo *philo)
{
	t_god	*info;

	info = philo->god;
	if (info->nb_philo == 1)
	{
		if_one_philo(info);
		return ;
	}
	pthread_mutex_lock(&(info->fork[philo->l_fork_id]));
	print_action(info, philo->philo_id, ""MAGENTA"has taken a fork"RESET"");
	pthread_mutex_lock(&(info->fork[philo->r_fork_id]));
	print_action(info, philo->philo_id, ""YELLOW"has taken a fork"RESET"");
	pthread_mutex_lock(&(info->check_meal));
	print_action(info, philo->l_fork_id, ""GREEN"is eating"RESET"");
	philo->last_time_eat = timestamp();
	// print_time(info);
	philo->x_eat++;
	pthread_mutex_unlock(&(info->check_meal));
	sleep_philo(info->time_eat, info);
	pthread_mutex_unlock(&(info->fork[philo->l_fork_id]));
	pthread_mutex_unlock(&(info->fork[philo->r_fork_id]));
}

static void	if_one_philo(t_god *info)
{
	int	death;

	death = 0;
	while (!death)
	{
		pthread_mutex_lock(&(info->check_meal));
		death = info->dead;
		pthread_mutex_unlock(&(info->check_meal));
	}
}

/*----------- 2.Sleep ---------------*/
void	sleep_philo(long long time, t_god *info)
{
	long long	current_time;
	(void) info;

	current_time = timestamp();
	// while (1)
	// {
	ft_msleep(time, info);
	pthread_mutex_lock(&(info->check_meal));
	if (info->dead)
	{
		pthread_mutex_unlock(&(info->check_meal));
		return ;
	}
	pthread_mutex_unlock(&(info->check_meal));
	if (passing_time(current_time, timestamp()) >= time)
		return ;
	// }
}

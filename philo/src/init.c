/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:26:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/12 14:14:11 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_mutex(t_god *info);
static void	init_philo(t_god *info);

/*----------- 1.General initialisation ---------------*/
int	init(t_god *info, char **av, int ac)
{
	info->nb_philo = ft_atoi(av[0]);
	info->time_death = ft_atoi(av[1]);
	info->time_eat = ft_atoi(av[2]);
	info->time_sleep = ft_atoi(av[3]);
	if (ms_checker(info->time_death, info->time_eat, info->time_sleep)
		|| !(info->nb_philo))
		return (2);
	info->dead = 0;
	info->all_philo_eaten = 0;
	if (ac == 5)
	{
		info->x_meal = ft_atoi(av[4]);
		if (info->x_meal <= 0)
			return (3);
	}
	else
		info->x_meal = -1;
	if (init_mutex(info))
		return (4);
	init_philo(info);
	return (SUCCESS);
}

/*----------- 2.Philosopher initialisation ---------------*/
static void	init_philo(t_god *info)
{
	int	i;

	i = info->nb_philo;
	while (--i >= 0)
	{
		info->philo[i].philo_id = i;
		info->philo[i].x_eat = 0;
		info->philo[i].l_fork_id = i;
		info->philo[i].r_fork_id = (i + 1) % info->nb_philo;
		info->philo[i].last_time_eat = 0;
		info->philo[i].god = info;
	}
}

/*----------- 3.Mutex initialisation ---------------*/
static int	init_mutex(t_god *info)
{
	int	i;

	i = info->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL))// --> Mutex initialiser
			return (ERROR);
	}
	if (pthread_mutex_init(&(info->check_meal), NULL))// --> Mutex initialiser
		return (ERROR);
	if (pthread_mutex_init(&(info->write), NULL))// --> Mutex initialiser
		return (ERROR);
	return (SUCCESS);
}


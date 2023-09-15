/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:27:48 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/15 20:07:58 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*----------- 1.Threads routine ---------------*/
void	*routine(void *philos)
{
	t_philo	*philo;
	t_god	*info;

	philo = (t_philo *)philos;
	info = philo->god;
	// pthread_mutex_lock(&(info->check_meal));
	// info->philo[philo->philo_id].last_time_eat = timestamp();
	// pthread_mutex_unlock(&(info->check_meal));
	if (philo->philo_id % 2)
		ft_msleep((info->time_eat / 2), info);
	while (1)
	{
		pthread_mutex_lock(&(info->check_meal));
		if (info->dead)
		{
			pthread_mutex_unlock(&(info->check_meal));
			break ;
		}
		pthread_mutex_unlock(&(info->check_meal));
		eat_philo(philo);
		pthread_mutex_lock(&(info->check_meal));
		if (info->all_philo_eaten)
		{
			pthread_mutex_unlock(&(info->check_meal));
			break ;
		}
		pthread_mutex_unlock(&(info->check_meal));
		print_action(info, philo->philo_id, ""BLUE"is sleeping"RESET"");
		sleep_philo(info->time_sleep, info);
		print_action(info, philo->philo_id, "is thinking");
	}
	return (NULL);
}

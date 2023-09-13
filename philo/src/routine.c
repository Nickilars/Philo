/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:27:48 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/13 12:52:27 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*----------- 1.Threads routine ---------------*/
void	*routine(void *philos)
{
	int		i;
	t_philo	*philo;
	t_god	*info;

	i = 0;
	philo = (t_philo *)philos;
	info = philo->god;
	if (philo->philo_id % 2)
		ft_usleep(150);
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
		if (info->all_philo_eaten)
			break;
		print_action(info, philo->philo_id, ""BLUE"is sleeping"RESET"");
		sleep_philo(info->time_sleep, info);
		print_action(info, philo->philo_id, "is thinking");
	}
	return (NULL);
}






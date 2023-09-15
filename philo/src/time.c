/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:52:50 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/15 19:54:29 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* ----------- 1.Timestamp ----------- */
long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* ----------- 2.Personal usleep ----------- */
void	ft_msleep(long long milliseconds, t_god *info)
{
	long long	start;

	start = timestamp();
	
	pthread_mutex_lock(&(info->check_meal));
	if (info->dead)
	{
		pthread_mutex_unlock(&(info->check_meal));
		return ;
	}
	pthread_mutex_unlock(&(info->check_meal));
	while (timestamp() < start + milliseconds)
		usleep(500);
}

/* ----------- 3.Microseconds checker for time ----------- */
int	ms_checker(int death, int sleep, int eat)
{
	if (death <= 60 || sleep <= 60 || eat <= 60)
		return (ERROR);
	return (SUCCESS);
}

/* ----------- 4.Passing time ----------- */
long long	passing_time(long long past, long long present)
{
	return (present - past);
}

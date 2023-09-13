/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:52:50 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/12 14:49:00 by nrossel          ###   ########.fr       */
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
void	ft_usleep(long long microseconds)
{
	long long	start;

	start = timestamp();
	while (timestamp() < start + microseconds)
		usleep(10);
}

/* ----------- 3.Microseconds checker for time ----------- */
int	ms_checker(int death, int sleep, int eat)
{
	if (death <= 60 || sleep <= 60 || eat <= 60 )
		return (ERROR);
	return (SUCCESS);
}

/* ----------- 4.Passing time ----------- */
long long	passing_time(long long past, long long present)
{
	return (present - past);
}
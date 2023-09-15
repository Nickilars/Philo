/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:41 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/14 14:01:01 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* ----------- 1.Atoi for philo ----------- */
int	ft_atoi(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret);
}

/* ----------- 2.Check nb args ----------- */
int	nbr_arg(int ac)
{
	if (ac < 4 || 7 <= ac)
		return (4);
	return (SUCCESS);
}

/* ----------- 3.Print actions ----------- */
void	print_action(t_god *info, int id, char *action)
{
	if (info->dead)
		return ;
	pthread_mutex_lock(&(info->write));
	printf("%lld ", passing_time(info->start_proc, timestamp()));
	printf("%d. ", id + 1);
	printf("%s\n", action);
	pthread_mutex_unlock(&(info->write));
}

/* ----------- 4.ft_strlen ----------- */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

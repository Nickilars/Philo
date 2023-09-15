/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:56:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/14 13:55:30 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_philo_struct(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->god->nb_philo)
	{
		printf("|------------------------------------|\n");
		printf("Struct adresse : %p\n", philo + i);
		printf("philo no.%d\n", philo[i].philo_id + 1);
		printf("Right fork value : %d\n", philo[i].r_fork_id);
		printf("Left fork value : %d\n", philo[i++].l_fork_id);
		printf("|------------------------------------|\n\n");
	}
}

void	print_struct(t_philo *philo)
{
	printf("|------------------------------------|\n");
	printf("Struct adresse : %p\n", philo);
	printf("philo no.%d\n", philo->philo_id + 1);
	printf("Right fork value : %d\n", philo->r_fork_id);
	printf("Left fork value : %d\n", philo->l_fork_id);
	printf("|------------------------------------|\n\n");
}

void	print_time(t_god *info)
{
	printf("|------------------------------------|\n");
	printf("Philo number: %d\n", info->nb_philo);
	printf("Meal number: %d\n", info->x_meal);
	printf("Time_to_die: %d\n", info->time_death);
	printf("Time_to_sleep: %d\n", info->time_sleep);
	printf("Time_to_eat: %d\n", info->time_eat);
	printf("|------------------------------------|\n\n");
}

void	print_current_time(long long past, char *ft)
{
	static int i;
	
	fprintf(stderr, "Fonction : %s ", ft);
	fprintf(stderr, "Time :%d: %lld\n", i++, passing_time(past, timestamp()));
}
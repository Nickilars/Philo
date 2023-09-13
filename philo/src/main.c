/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:55:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/13 14:04:07 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_error(int error);
static int	check_init(t_god *info, char **av, int ac);

/*----------- 1.Main function ---------------*/
int	main(int ac, char **av)
{
	t_god	info;

	if (check_init(&info, av, ac))
		return (ERROR);
	if (start_threads(&info))
		return (ERROR);
	return (SUCCESS);
}

/*----------- 2.If error ---------------*/
static int	is_error(int error)
{
	if (error == 1)
		return (error_msg("invalide argument"));
	else if (error == 2)
		return (error_msg("time/philo number invalide"));
	else if (error == 3)
		return (error_msg("meal number invalide"));
	else if (error == 4)
		return (error_msg("initialization"));
	return (SUCCESS);
}

/*----------- 3.Check init & arg number ---------------*/
static int	check_init(t_god *info, char **av, int ac)
{
	if (is_error(nbr_arg(ac)))
		return (1);
	if (is_error(init(info, av + 1, ac - 1)))
		return (1);
	return (0);
}

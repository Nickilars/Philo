/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:20:43 by nrossel           #+#    #+#             */
/*   Updated: 2023/09/07 10:45:04 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error_msg(char *str)
{
	write (2, ""RED"Error"RESET": ", 21);
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	return (ERROR);
}
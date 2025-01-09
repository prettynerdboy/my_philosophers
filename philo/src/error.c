/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:51:49 by anakin            #+#    #+#             */
/*   Updated: 2025/01/09 19:51:53 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handler(int error_num)
{
	if (error_num == ARGS_ERROR)
		ft_putstr_fd("*** ARGUMENT ERROR ***\n", STDERR_FILENO);
	if (error_num == MALLOC_ERROR)
		ft_putstr_fd("*** MALLOC ERROR ***\n", STDERR_FILENO);
	if (error_num == TIME_ERROR)
		ft_putstr_fd("*** GETTIMEOFDAY ERROR ***\n", STDERR_FILENO);
	if (error_num == PTHREAD_ERROR)
		ft_putstr_fd("*** PTHREAD ERROR ***\n", STDERR_FILENO);
	return (-1);
}

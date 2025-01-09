/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:52:34 by anakin            #+#    #+#             */
/*   Updated: 2025/01/09 19:52:37 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init(int argc, char *argv[], t_info *info)
{
	int				func_return;
	t_time			time;

	func_return = init_info(argc, argv, info, &time);
	if (func_return)
		return (error_handler(func_return));
	init_philo_fork(info);
	return (0);
}

void	destroy_mutex(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&info->msg_mutex);
	pthread_mutex_destroy(&info->num_mutex);
	i = 0;
	while (i < info->num_of_philos)
	{
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&info->sts_mutexs[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_info			info;
	int				event_res;

	if (!(argc == MUST_ARGS_NUM || argc == ADDED_ARGS_NUM))
		return (error_handler(ARGS_ERROR));
	if (init(argc, argv, &info))
		return (-1);
	event_res = event_start(&info);
	if (event_res == MALLOC_ERROR || event_res == PTHREAD_ERROR)
	{
		error_handler(event_res);
		return (-1);
	}
	destroy_mutex(&info);
	return (0);
}

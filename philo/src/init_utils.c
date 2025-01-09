/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:52:19 by anakin            #+#    #+#             */
/*   Updated: 2025/01/09 19:52:22 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	t_time	time;
	long	res;

	gettimeofday(&time, NULL);
	res = adj_time_form(&time);
	return (res);
}

void	mod_usleep(int sleep_time)
{
	long	end;

	end = get_time() + sleep_time;
	while (get_time() <= end)
		;
}

int	init_sts(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_mutex_init(&info->sts_mutexs[i], NULL))
			return (PTHREAD_ERROR);
		i++;
	}
	return (0);
}

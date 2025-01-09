/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:52:47 by anakin            #+#    #+#             */
/*   Updated: 2025/01/09 19:52:49 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*set_fin_philos(t_info *info, int dead_philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (i != dead_philo)
			pthread_mutex_lock(&info->sts_mutexs[i]);
		info->fin = FINISH;
		if (i != dead_philo)
			pthread_mutex_unlock(&info->sts_mutexs[i]);
		i++;
	}
	return (NULL);
}

void	unlock_all_sts(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		pthread_mutex_unlock(info->philos[i].sts_mutex);
		i++;
	}
}

void	lock_all_sts(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		pthread_mutex_lock(info->philos[i].sts_mutex);
		i++;
	}
}

int	inc_ach(t_info *info, int ach_num, int i)
{
	pthread_mutex_lock(info->philos[i].sts_mutex);
	if (info->philos[i].eat_times >= info->must_eat_num)
		ach_num++;
	pthread_mutex_unlock(info->philos[i].sts_mutex);
	return (ach_num);
}

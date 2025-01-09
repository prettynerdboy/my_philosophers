/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:52:10 by anakin            #+#    #+#             */
/*   Updated: 2025/01/09 19:52:13 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_start(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->sts_mutex);
		if (philo->status == GO)
		{
			pthread_mutex_unlock(philo->sts_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->sts_mutex);
	}
}

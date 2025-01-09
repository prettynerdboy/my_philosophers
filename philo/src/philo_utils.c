/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:53:08 by anakin            #+#    #+#             */
/*   Updated: 2025/01/09 19:53:10 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	adj_time_form(t_time *time)
{
	long	res;

	res = time->tv_sec * 1000;
	res += time->tv_usec / 1000;
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while ((size_t)INT_MAX < len)
	{
		write(fd, s, INT_MAX);
		len -= INT_MAX;
		s += INT_MAX;
	}
	write(fd, s, len);
}

size_t	ft_strlen(const char *str)
{
	size_t	size;
	char	*s;

	s = (char *)str;
	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		flag;
	size_t	i;

	flag = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			flag *= -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (NOTSET);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (NOTSET);
	return (res * flag);
}

int	ph_atoi(const char *str)
{
	long	tmp;

	tmp = ft_atol(str);
	if (tmp == NOTSET || tmp <= 0 || tmp > INT_MAX)
		return (NOTSET);
	return ((int)tmp);
}

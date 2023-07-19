/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:02 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/19 15:31:25 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_stamp(long long time_start)
{
	return (ft_gettime() - time_start);
}

void	ft_usleep(uint64_t time_sleep)
{
	long long	now;
	long long	after;

	now = ft_gettime();
	after = now + time_sleep;
	while (now < after)
	{
		usleep(100);
		now = ft_gettime();
	}
}
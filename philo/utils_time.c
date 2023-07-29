/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:02 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/28 17:11:05 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_converttime(struct timeval time_now)
{
	return ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));
}

long long	time_stamp(long long time_stamp)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (ft_converttime(time) - time_stamp);
}

long long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// long long	time_stamp(long long time_start)
// {
// 	return (ft_gettime() - time_start);
// }

void	ft_usleep(long long time_sleep)
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

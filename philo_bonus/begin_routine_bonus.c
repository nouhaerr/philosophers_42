/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:01:22 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/29 02:10:15 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	write_status(t_philo *philo, char *action)
{
	if (*action == 'd')
	{
		sem_wait(philo->philo_inf->status);
		printf("%lld ms %d %s\n",
			time_stamp((philo->philo_inf->start_time.tv_sec * 1000)
				+ (philo->philo_inf->start_time.tv_usec / 1000)), \
				philo->ph_id, action);
	}
	else
	{
		sem_wait(philo->philo_inf->status);
		printf("%lld ms %d %s\n",
			time_stamp((philo->philo_inf->start_time.tv_sec * 1000)
				+ (philo->philo_inf->start_time.tv_usec / 1000)), \
				philo->ph_id, action);
		sem_post(philo->philo_inf->status);
	}
}

void	is_sleeping(t_philo *philo)
{
	write_status(philo, "is sleeping");
	ft_usleep(philo->philo_inf->t_to_sleep);
}

void	is_thinking(t_philo *philo)
{
	write_status(philo, "is thinking");
}

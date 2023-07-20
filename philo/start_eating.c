/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:11:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/20 01:23:00 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_status(philo, "has taken a fork 🍽️");
	pthread_mutex_lock(philo->l_fork);
	write_status(philo, "has taken a fork 🍽️");
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	is_eating(t_philo *philo)
{
	take_forks(philo);
	write_status(philo, "is eating 🍝");
	ft_usleep(philo->philo_inf.t_to_eat);
	put_down_forks(philo);
	philo->time_of_last_meal = ft_gettime();
	if (philo->philo_inf.t_of_each_ph_must_eat != 0)
	{
		philo->philo_inf.t_of_each_ph_must_eat--;
		if (philo->philo_inf.t_of_each_ph_must_eat == 0)
			return (0);
	}
	return (1);
}

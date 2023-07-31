/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:11:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/08/01 00:52:09 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	write_status(philo, "has taken a fork");
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	is_eating(t_philo *philo)
{
	take_forks(philo);
	gettimeofday(&philo->time_of_last_meal, NULL);
	write_status(philo, "is eating");
	ft_usleep(philo->philo_inf->t_to_eat);
	philo->count_meals++;
	put_down_forks(philo);
}

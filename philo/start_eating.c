/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:11:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/19 15:34:18 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->right = 1;
	write_status(philo, "has taken a fork 🍽️");
	pthread_mutex_lock(philo->l_fork);
	philo->left = 1;
	write_status(philo, "has taken a fork 🍽️");
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	is_eating(t_philo *philo)
{
	take_forks(philo);
	philo->time_of_last_meal = ft_gettime();
	write_status(philo, "is eating 🍝");
	ft_usleep(philo->philo_inf.t_to_eat * 1000);
	if (philo->left + philo->right == 2)
		philo->count_meals++;
	put_down_forks(philo);
}

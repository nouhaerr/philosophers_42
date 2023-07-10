/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:11:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 23:40:12 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_taking_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	write_status(philo, "has taken a fork");
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	is_eating(t_philo *philo)
{
	is_taking_fork(philo);
	gettimeofday(&philo->time_of_last_meal, NULL);
	write_status(philo, "is eating");
	put_down_forks(philo);
}

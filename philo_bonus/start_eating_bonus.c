/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:11:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/29 02:55:52 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->forks);
	write_status(philo, "has taken a fork");
	sem_wait(philo->forks);
	write_status(philo, "has taken a fork");
}

void	put_down_forks(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	is_eating(t_philo *philo)
{
	take_forks(philo);
	gettimeofday(&philo->time_of_last_meal, NULL);
	sem_wait(philo->philo_inf->check_die);
	philo->t_of_each_ph_must_eat--;
	sem_post(philo->philo_inf->check_die);
	write_status(philo, "is eating");
	ft_usleep(philo->philo_inf->t_to_eat);
	put_down_forks(philo);
}

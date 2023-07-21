/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:11:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/21 17:52:07 by nerrakeb         ###   ########.fr       */
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

int	is_eating(t_philo *philo)
{
	take_forks(philo);
	gettimeofday(&philo->time_of_last_meal, NULL);
	write_status(philo, "is eating");
	ft_usleep(philo->philo_inf.t_to_eat);
	put_down_forks(philo);
	if (philo->philo_inf.t_of_each_ph_must_eat != 0)
	{
		philo->philo_inf.t_of_each_ph_must_eat--;
		if (philo->philo_inf.t_of_each_ph_must_eat == 0)
			return (0);
	}
	return (1);
}

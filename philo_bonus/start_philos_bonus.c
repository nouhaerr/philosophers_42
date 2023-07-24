/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:47:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/24 22:48:10 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_die(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		sem_wait(philo->philo_inf.check_die);
		if (time_stamp((philo->time_of_last_meal.tv_sec * 1000)
				+ (philo->time_of_last_meal.tv_usec / 1000))
			>= philo->philo_inf.t_to_die)
		{
			write_status(philo, "died");
			exit(2);
		}
		sem_post(philo->philo_inf.check_die);
		usleep(100);
	}
}

void	philo_routine(t_philo *philo)
{
	gettimeofday(&philo->time_of_last_meal, NULL);
	if (pthread_create(&philo->tid, NULL, &check_die, philo) != 0)
		exit(1);
	if (pthread_detach(philo->tid) != 0)
		exit(1);
	// if (philo->ph_id % 2 == 0)
	// 	ft_usleep(philo->philo_inf.t_to_eat);
	gettimeofday(&philo->time_of_last_meal, NULL);
	while (1)
	{
		if (!is_eating(philo))
			break ;
		is_sleeping(philo);
		is_thinking(philo);
	}
	sem_unlink("/forks");
	sem_unlink("/status");
	sem_unlink("/check_die");
	sem_close(philo->philo_inf.ph_forks);
	sem_close(philo->philo_inf.status);
	sem_close(philo->philo_inf.check_die);
	exit(1);
}

void	start_philos(t_philo *philo, t_data data)
{
	int	i;

	i = -1;
	while (++i < data.nbr_of_ph)
	{
		philo[i].pid = fork();
		if (philo[i].pid == -1)
			exit(1);
		if (philo[i].pid == 0)
		{
			philo[i].forks = data.ph_forks;
			philo[i].philo_inf = data;
			philo[i].ph_id = i + 1;
			philo_routine(&philo[i]);
		}
	}
}

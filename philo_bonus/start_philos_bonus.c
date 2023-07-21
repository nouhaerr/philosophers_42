/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:47:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/21 19:49:25 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_die(void *args)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)args;
	i = -1;
	if (time_stamp((philo->philo_inf.start_time.tv_sec * 1000)
		+ (philo->philo_inf.start_time.tv_usec / 1000)) >= philo->philo_inf.t_to_die)
	{
		write_status(philo, "died");
		exit(EXIT_FAILURE);
	}
}

void	philo_routine(t_philo *philo)
{
	if (pthread_create(&philo->tid, NULL, &check_die, philo) != 0)
		exit(1);
	if (pthread_detach(philo->tid) != 0)
		exit(1);
	if (philo->ph_id % 2 == 0)
		ft_usleep(philo->philo_inf.t_to_eat);
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
	free(philo);
	exit(EXIT_SUCCESS);
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
			philo[i].philo_inf = data;
			philo[i].ph_id = i + 1;
			gettimeofday(&philo->time_of_last_meal, NULL);
			philo[i].forks = data.ph_forks;
			philo_routine(&philo[i]);
		}
	}
}

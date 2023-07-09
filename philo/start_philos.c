/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:47:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 23:44:14 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		is_eating(philo);
		// is_sleeping(philo);
		// is_thinking(philo);
	}
	return (NULL);
}

int	start_philos(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		printf("Thread %d has started\n", philo[i].ph_id);
		if (pthread_create(&philo[i].th, NULL, &routine, &philo[i]) != 0)
		{
			printf("Failed to create thread\n");
			return (0);
		}
	}
	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (0);
	}
	return (1);
}

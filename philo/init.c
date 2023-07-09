/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:06:16 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 22:50:31 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nbr_of_ph);
	if (!data->forks)
		return (printf("Allocation Failed !!\n"));
	pthread_mutex_init(&data->status, NULL);
	while (i < data->nbr_of_ph)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_philo(t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	while (i < data.nbr_of_ph)
	{
		philo[i].philo_inf = data;
		philo[i].ph_id = i + 1;
		philo[i].r_fork = philo[i].philo_inf.forks[i];
		philo[i].l_fork = philo[i].philo_inf.forks[(i + 1) % data.nbr_of_ph];
		printf("HERE\n");
		i++;
	}
	return (1);
}

int	start_problem(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		printf("Thread %d has started\n", i);
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

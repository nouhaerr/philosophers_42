/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/20 22:22:45 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_info(t_data info)
{
	int	i;

	i = -1;
	while (++i < info.nbr_of_ph)
	{
		pthread_mutex_destroy(&info.forks[i]);
	}
	pthread_mutex_destroy(&info.status);
	pthread_mutex_destroy(&info.die_lock);
	free(info.forks);
}

void	destroy_philo(t_philo *philo)
{
	pthread_mutex_destroy(philo[0].meals);
	free(philo->meals);
	free(philo->count_meals);
	free(philo);
}

int	check_die(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		pthread_mutex_lock(&philo->philo_inf.die_lock);
		if (ft_gettime() - philo->time_of_last_meal
			>= philo->philo_inf.t_to_die)
		{
			write_status(&philo[i], "died ☠️");
			destroy_info(philo->philo_inf);
			destroy_philo(philo);
			return (1);
		}
		pthread_mutex_unlock(&philo->philo_inf.die_lock);
	}
	return (0);
}

int	philo_wait(t_philo *philo)
{
	while (1)
	{
		if (check_die(philo))
			return (1);
		usleep(100);
		pthread_mutex_lock(philo->meals);
		if (*(philo->count_meals) == philo->philo_inf.nbr_of_ph)
			return (1);
		pthread_mutex_unlock(philo->meals);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (printf("Invalid number of arguments !!\n"));
	if (!check_args(av) || !init_data(av, &data))
		return (printf("Wrong Arguments !!\n"));
	philo = (t_philo *)malloc(data.nbr_of_ph * sizeof(t_philo));
	if (!philo)
		return (printf("Allocation Failed !!\n"));
	if (init_philo(philo, data))
		return (1);
	if (start_philos(philo))
		return (1);
	if (philo_wait(philo))
		return (1);
	return (0);
}

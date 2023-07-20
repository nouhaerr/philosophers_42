/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/20 01:59:39 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_ph_info(t_data ph_inf)
{
	int	i;

	i = -1;
	while (++i < ph_inf.nbr_of_philo)
	{
		pthread_mutex_destroy(&ph_inf->forks[i]);
	}
	pthread_mutex_destroy(&ph_inf->status);
	pthread_mutex_destroy(&ph_inf->die);
	free(ph_inf->forks);
}

void	destroy_philo(t_philo *philo)
{
	pthread_mutex_destroy(philo[0]->meals);
	free(philo->meals);
	free(philo);
}

void	check_die(t_philo *philo)
{
	long long	time;
	int			i;

	time = 0;
	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		pthread_mutex_lock(philo->philo_inf.die);
		time = ft_gettime() - philo[i].time_of_last_meal;
		if (time >= philo[i].philo_inf.t_to_die)
		{ 
			write_status(philo[i], "died ☠️");
			destroy_ph_info(philo->philo_inf);
			destroy_philo(philo);
			return (1);
		}
		pthread_mutex_unlock(philo->philo_inf.die);
	}
	return (0);
}

void	philo_wait(t_philo *philo)
{
	while (1)
	{
		if (check_die(philo))
			return (1);
		// pthread_mutex_lock(philo->die);
		// if (*(philo->die) == 0)
		// 	break ;
		// pthread_mutex_unlock(philo->die);
		pthread_mutex_lock(philo->meals);
		if (philo->philo_inf.nbr_of_ph == *(philo->count_meals))
			return (1) ;
		pthread_mutex_unlock(philo->meals);
		usleep(50);
	}
	return (0);
}

int	main(int ac, char **av)
{
    t_data data;
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

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

void	check_die(t_philo *philo)
{
	long long	time;
	int			i;

	time = 0;
	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		time = ft_gettime() - philo[i].time_of_last_meal;
		if (time >= philo[i].philo_inf.t_to_die)
		{
			// pthread_mutex_lock(philo->die);
			// *(philo->die) = 0; 
			write_status(philo, "died ☠️");
			// pthread_mutex_unlock(philo->die);
		}
	}
}

void	philo_wait(t_philo *philo)
{
	while (1)
	{
		// pthread_mutex_lock(philo->die);
		// if (*(philo->die) == 0)
		// 	break ;
		// pthread_mutex_unlock(philo->die);
		pthread_mutex_lock(philo->meals);
		if (philo->philo_inf.nbr_of_ph == *(philo->count_meals))
			break ;
		pthread_mutex_unlock(philo->meals);
		usleep(50);
	}
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
	if (!start_philos(philo))
		return (1);
	philo_wait(philo);
	free(philo);
	return (0);
}

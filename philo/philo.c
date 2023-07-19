/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/19 17:39:59 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_philo *philo)
{
	long long	time;
	int			i;

	time = 0;
	i = -1;
	while (++i < philo->philo_inf.nbr_of_ph)
	{
		time = ft_gettime() - philo->time_of_last_meal;
		if (time >= philo->philo_inf.t_to_die)
		{
			write_status(philo, "died ☠️");
			return (1);
		}
	}
	pthread_mutex_lock(&philo->philo_inf.meals);
	if (philo->philo_inf.nbr_of_ph == philo->philo_inf.count_meals)
		return (1);
	pthread_mutex_unlock(&philo->philo_inf.meals);
	return (0);
}

void	philo_wait(t_philo *philo)
{
	while (1)
	{
		if (check_die(philo))
			break ;
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
	if (!init_philo(philo, data))
		return (1);
	if (!start_philos(philo))
		return (1);
	philo_wait(philo);
	free(philo);
	return (0);
}

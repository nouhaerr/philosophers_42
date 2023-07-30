/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/30 02:47:59 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_info(t_data *info)
{
	int	i;

	i = -1;
	while (++i < info->nbr_of_ph)
	{
		pthread_mutex_destroy(&info->forks[i]);
	}
	pthread_mutex_destroy(&info->status);
	pthread_mutex_destroy(&info->die_lock);
	free(info->forks);
	free(info);
}

void	destroy_philo(t_philo *philo)
{
	pthread_mutex_destroy(philo[0].meals);
	free(philo->meals);
	free(philo);
}

int	check_full_eat(t_philo *philo)
{
	int	x;
	int	i;

	i = -1;
	x = 0;
	while (++i < philo->philo_inf->nbr_of_ph)
	{
		pthread_mutex_lock(philo->meals);
		if (philo[i].full == 1)
			x++;
		pthread_mutex_unlock(philo->meals);
	}
	if (x == philo->philo_inf->nbr_of_ph)
	{
		pthread_mutex_lock(&philo->philo_inf->status);
		return (1);
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_inf->nbr_of_ph)
	{
		pthread_mutex_lock(&philo->philo_inf->die_lock);
		if (time_stamp((philo->time_of_last_meal.tv_sec * 1000)
				+ (philo->time_of_last_meal.tv_usec / 1000))
			>= philo->philo_inf->t_to_die)
		{
			pthread_mutex_lock(&philo->philo_inf->status);
			printf("%lld ms %d %s\n",
				time_stamp((philo->philo_inf->start_time.tv_sec * 1000)
					+ (philo->philo_inf->start_time.tv_usec / 1000)), \
				philo->ph_id, "died");
			destroy_info(philo->philo_inf);
			destroy_philo(philo);
			return (1);
		}
		pthread_mutex_unlock(&philo->philo_inf->die_lock);
	}
	if (check_full_eat(philo))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (printf("Invalid number of arguments !!\n"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Allocation Failed !!\n"));
	if (!check_args(av) || !init_data(av, data))
		return (printf("Wrong Arguments !!\n"));
	philo = (t_philo *)malloc(data->nbr_of_ph * sizeof(t_philo));
	if (!philo)
		return (printf("Allocation Failed !!\n"));
	if (init_philo(philo, data))
		return (1);
	if (start_philos(philo))
		return (1);
	while (1)
	{
		if (check_death(philo))
			break ;
	}
	return (0);
}

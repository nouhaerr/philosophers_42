/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:06:16 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/20 01:13:56 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nbr_of_ph);
	if (!data->forks)
		return (printf("Allocation Failed !!\n"));
	pthread_mutex_init(&data->status, NULL);
	pthread_mutex_init(&data->die, NULL);
	return (0);
}

int	init_data(char **av, t_data *ph_info)
{
	if (!is_empty(av))
		return (0);
	ph_info->nbr_of_ph = ft_atoi(av[1]);
	ph_info->t_to_die = ft_atoi(av[2]); // check if < 60
	ph_info->t_to_eat = ft_atoi(av[3]); // check if < 60 return 1;
	ph_info->t_to_sleep = ft_atoi(av[4]); // check if < 60
	ph_info->t_of_each_ph_must_eat = 0;
	if (av[5])
	{
		ph_info->t_of_each_ph_must_eat = ft_atoi(av[5]);
		if (ph_info->t_of_each_ph_must_eat == 0)
			return (0);
	}
	if (ph_info->nbr_of_ph < 1 || ph_info->t_to_die < 1 || ph_info->t_to_eat < 1
		|| ph_info->t_to_sleep < 1 || ph_info->t_of_each_ph_must_eat < 0)
		return (0);
	if (init_mutex(ph_info))
		return (0);
	ph_info->start_time = ft_gettime();
	return (1);
}

int	init_philo(t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	philo->meals = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data.nbr_of_ph);
	philo->count_meals = (int *)malloc(sizeof(int) * data.nbr_of_ph);
	if (!philo->meals || !philo->count_meals)
		return (printf("Allocation Failed !!\n"));
	philo->count_meals[0] = 0;
	while (i < data.nbr_of_ph)
	{
		if (pthread_mutex_init(&data.forks[i], NULL) != 0)
			return (1);
		pthread_mutex_init(&philo->meals[i], NULL);
		philo[i].philo_inf = data;
		philo[i].ph_id = i + 1;
		philo[i].time_of_last_meal = ft_gettime();
		philo[i].meals = philo->meals;
		philo[i].count_meals = &philo->count_meals[0];
		philo[i].r_fork = &data.forks[i];
		philo[i].l_fork = &data.forks[(i + 1) % data.nbr_of_ph];
		i++;
	}
	return (0);
}

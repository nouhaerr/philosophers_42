/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:47:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/30 03:23:47 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->philo_inf->status);
	printf("%lld ms %d %s\n",
		time_stamp((philo->philo_inf->start_time.tv_sec * 1000)
			+ (philo->philo_inf->start_time.tv_usec / 1000)), \
			philo->ph_id, action);
	pthread_mutex_unlock(&philo->philo_inf->status);
}

void	is_sleeping(t_philo *philo)
{
	write_status(philo, "is sleeping");
	ft_usleep(philo->philo_inf->t_to_sleep);
}

void	is_thinking(t_philo *philo)
{
	write_status(philo, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ph_id % 2 == 0)
		ft_usleep(philo->philo_inf->t_to_eat);
	while (1)
	{
		is_eating(philo);
		pthread_mutex_lock(philo->meals);
		if (philo->philo_inf->t_of_each_ph_must_eat != 0
			&& philo->count_meals == philo->philo_inf->t_of_each_ph_must_eat)
			philo->full++;
		pthread_mutex_unlock(philo->meals);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

int	start_philos(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_inf->nbr_of_ph)
	{
		if (pthread_create(&philo[i].tid, NULL, &routine, &philo[i]) != 0)
			return (1);
		if (pthread_detach(philo[i].tid) != 0)
			return (1);
		usleep(50);
	}
	return (0);
}

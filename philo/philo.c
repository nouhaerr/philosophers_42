/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/19 15:17:41 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	int			i;
	long long	time;

	time = 0;
	while (1)
	{
		i = -1;
		while (++i < philo->philo_inf.nbr_of_ph)
		{
			time = ft_gettime() - philo->time_of_last_meal;
			if (time > philo->philo_inf.t_to_die)
			{
				pthread_mutex_lock(&philo->philo_inf.status);
				printf("%lld ms Philosopher %d died ☠️\n", time_stamp(philo->philo_inf.start_time), philo->ph_id);
				return ;
			}
			else if (philo->philo_inf.t_of_each_ph_must_eat != 0 
				&& philo->philo_inf.t_of_each_ph_must_eat == philo->count_meals)
				return ;
		}
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
	check_die(philo);
	free(philo);
	return (0);
}

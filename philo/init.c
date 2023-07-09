/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:06:16 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 01:56:10 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	(void)arg;
	printf("hello\n");
	return (NULL);
}

int	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	// printf("%d\n", philo->philo_inf.nbr_of_ph);
	while (i < philo->philo_inf.nbr_of_ph)
	{
		printf("Thread has started\n");
		if (pthread_create(&philo[i].id, NULL, &routine, NULL) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->philo_inf.nbr_of_ph)
	{
		if (pthread_join(philo[i].id, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

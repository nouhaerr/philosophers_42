/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:06:16 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 02:48:00 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	(void)arg;
	printf("hello\n");
	return (NULL);
}

int	init_philo(t_philo *philo, t_data ph_inf)
{
	int	i;

	i = 0;
	// while ()
	printf("%d\n", philo->philo_inf.nbr_of_ph);
	while (i < ph_inf.nbr_of_ph)
	{
		printf("Thread has started\n");
		if (pthread_create(&(philo[i]).th, NULL, &routine, NULL) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < ph_inf.nbr_of_ph)
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

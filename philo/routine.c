/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:47:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 23:01:44 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	philo->right = 0;
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_lock(&philo->l_fork);
	philo->left = 0;
	pthread_mutex_unlock(&philo->l_fork);
}

void	is_eating(t_philo *philo)
{
	
}

void	*routine(void *arg)
{
	// (void)arg;
	t_philo	*philo = (t_philo *)arg;
	while (1)
	{
		is_taking_fork(philo);
		is_eating(philo);
	}
	return (NULL);
}

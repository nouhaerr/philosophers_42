/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:06:16 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/29 02:33:58 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/status");
	sem_unlink("/check_die");
	data->ph_forks = sem_open("/forks", O_CREAT, 0644, data->nbr_of_ph);
	data->status = sem_open("/status", O_CREAT, 0644, 1);
	data->check_die = sem_open("/check_die", O_CREAT, 0644, 1);
	if (data->ph_forks == SEM_FAILED || data->status == SEM_FAILED
		|| data->check_die == SEM_FAILED)
	{
		printf("Error: Semaphore was not created\n");
		exit(EXIT_FAILURE);
	}
}

void	init_data(char **av, t_data *ph_info)
{
	if (!is_empty(av))
		exit(EXIT_FAILURE);
	ph_info->nbr_of_ph = ft_atol(av[1]);
	ph_info->t_to_die = ft_atol(av[2]);
	ph_info->t_to_eat = ft_atol(av[3]);
	ph_info->t_to_sleep = ft_atol(av[4]);
	if (ph_info->nbr_of_ph < 1 || ph_info->t_to_die < 1
		|| ph_info->t_to_eat < 1 || ph_info->t_to_sleep < 1)
		exit(EXIT_FAILURE);
	init_sem(ph_info);
	gettimeofday(&ph_info->start_time, NULL);
}

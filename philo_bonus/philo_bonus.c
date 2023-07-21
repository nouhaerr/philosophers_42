/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:52:59 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/21 23:40:08 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_destroy(t_philo *philo)
{
	sem_unlink("/forks");
	sem_unlink("/status");
	sem_unlink("/check_die");
	sem_close(philo->philo_inf.ph_forks);
	sem_close(philo->philo_inf.status);
	sem_close(philo->philo_inf.check_die);
	free(philo);
	exit(EXIT_SUCCESS);
}

void	philo_wait(t_philo *philo)
{
	int	i;
	int	status;

	while (1)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while(i < philo->philo_inf.nbr_of_ph)
			{
				kill(philo[i].pid, SIGTERM);
				i++;
			}
			break ;
		}
	}
	philo_destroy(philo);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (printf("Invalid number of arguments !!\n"));
	if (!check_args(av))
		return (printf("Wrong Arguments !!\n"));
	init_data(av, &data);
	philo = (t_philo *)malloc(data.nbr_of_ph * sizeof(t_philo));
	if (!philo)
		return (printf("Allocation Failed !!\n"));
	start_philos(philo, data);
	philo_wait(philo);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:52:59 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/30 01:43:41 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_destroy(t_philo *philo, t_data *data)
{
	sem_close(data->ph_forks);
	sem_close(data->status);
	sem_close(data->check_die);
	sem_unlink("/forks");
	sem_unlink("/status");
	sem_unlink("/check_die");
	free(data);
	free(philo);
	exit(EXIT_SUCCESS);
}

void	philo_wait(t_philo *philo, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	waitpid(-1, &status, 0);
	while (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		if (waitpid(-1, &status, 0) < 0)
			break ;
	}
	while (i < data->nbr_of_ph)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	philo_destroy(philo, data);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (printf("Invalid number of arguments !!\n"));
	if (!check_args(av))
		return (printf("Wrong Arguments !!\n"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Allocation Failed !!\n"));
	init_data(av, data);
	philo = (t_philo *)malloc(data->nbr_of_ph * sizeof(t_philo));
	if (!philo)
		return (printf("Allocation Failed !!\n"));
	start_philos(av, philo, data);
	philo_wait(philo, data);
	return (0);
}

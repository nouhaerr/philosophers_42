/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 02:48:08 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    t_data ph_inf;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
	{
		printf("Invalid number of arguments !!\n");
		return (0);
	}
	if (!check_args(av) || !check_philo(av, &ph_inf))
		return (0);
	philo = (t_philo *)ft_calloc(ph_inf.nbr_of_ph, sizeof(t_philo));
	if (!philo)
		return (printf("Allocation Failed !!\n"));
	printf("%d\n", ph_inf.nbr_of_ph);
	if (!init_philo(philo, ph_inf))
		return (0);
	//should check the return of pthread_create for errors
	free(philo);
}

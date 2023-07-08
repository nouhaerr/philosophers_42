/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:46 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/07 16:53:13 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    t_data ph_inf;

	if (ac == 5 || ac == 6)
	{
		if (!check_args(av) || !check_philo(ac, av, &ph_inf))
			return (printf("Wrong arguments !!\n"));
		//should check the return of pthread_create for errors
	}
	else
		printf("Invalid number of arguments !!\n");
}

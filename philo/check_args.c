/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:53:42 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/07 16:37:32 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!_isdigit(av[i][j])) // || av[i][j] >= 123
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_philo(int ac, char **av)
{
	if (!is_empty(av))
		return (0);
	ph_info = (t_data *)malloc(sizeof(t_data) * 5);
	if (!ph_info)
		return (printf("Allocation Failed !!\n"));
	ph_info->nbr_of_ph = ft_atoi(av[1]);
	ph_info->t_to_die = ft_atoi(av[2]);
	ph_info->t_to_eat = ft_atoi(av[3]);
	ph_info->t_to_sleep = ft_atoi(av[4]);
	ph_info->t_of_each_ph_must_eat = 0;
	if (ac == 6)
		ph_info->t_of_each_ph_must_eat = ft_atoi(av[5]);
	return (1);
}

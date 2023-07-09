/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:53:42 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 01:28:55 by nerrakeb         ###   ########.fr       */
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
			if (!_isdigit(av[i][j]) && av[i][j] > 32) // check if the space is an error or not
			{
				printf("Wrong Arguments !!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_philo(char **av, t_data *ph_info)
{
	if (!is_empty(av))
		return (0);
	ph_info->nbr_of_ph = ft_atoi(av[1]);
	if (ph_info->nbr_of_ph == 0)
		return (0);
	ph_info->t_to_die = ft_atoi(av[2]);
	ph_info->t_to_eat = ft_atoi(av[3]);
	ph_info->t_to_sleep = ft_atoi(av[4]);
	ph_info->t_of_each_ph_must_eat = 0;
	if (av[5])
	{
		ph_info->t_of_each_ph_must_eat = ft_atoi(av[5]);
		if (ph_info->t_of_each_ph_must_eat == 0)
			return (0);
	}
	if (ph_info->nbr_of_ph < 0 || ph_info->t_to_die < 0
		|| ph_info->t_to_eat < 0 || ph_info->t_to_sleep < 0
		|| ph_info->t_of_each_ph_must_eat < 0)
		return (0);
	return (1);
}

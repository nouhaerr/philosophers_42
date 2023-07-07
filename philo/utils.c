/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:57:21 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/07 16:23:18 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	is_empty(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					signe;
	int					i;

	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (signe > 0 && nbr >= 9223372036854775807)
		return (-1);
	else if (signe < 0 && nbr > 9223372036854775807)
		return (0);
	return (nbr * signe);
}

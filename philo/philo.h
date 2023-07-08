/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:45:51 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/07 21:48:59 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	int	nbr_of_ph;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	t_of_each_ph_must_eat;
}	t_data;

typedef struct s_prog
{
	t_data			*philo_inf;
	pthread_mutex_t	mutex;
}	t_prog;

int	_isdigit(int c);
int	ft_atoi(const char *str);
int	is_empty(char **av);
int	check_args(char **av);
int	check_philo(int ac, char **av);

#endif

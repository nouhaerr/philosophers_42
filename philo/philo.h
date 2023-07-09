/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:45:51 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/09 01:36:27 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_data
{
	int	nbr_of_ph;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	t_of_each_ph_must_eat;
}	t_data;

typedef struct s_philo
{
	pthread_t		id;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	struct s_data	philo_inf;
}	t_philo;

int		_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		is_empty(char **av);
int		check_args(char **av);
int		check_philo(char **av, t_data *ph_info);
int		init_philo(t_philo *philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:45:51 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/18 16:27:31 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nbr_of_ph;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				t_of_each_ph_must_eat;
	pthread_mutex_t	status;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	pthread_t		tid;
	int				ph_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				left;
	int				right;
	int				count_meals;
	long			time_of_last_meal;
	t_data			philo_inf;
}	t_philo;

int			_isdigit(int c);
int			ft_atoi(const char *str);
int			is_empty(char **av);
int			check_args(char **av);
int			init_data(char **av, t_data *ph_info);
int			init_philo(t_philo *philo, t_data ph_inf);
int			start_philos(t_philo *philo);
void		*routine(void *arg);
void		take_forks(t_philo *philo);
void		is_eating(t_philo *philo);
void		write_status(t_philo *philo, char *action);
void		ft_usleep(uint64_t to_sleep);
long long	ft_gettime(void);

#endif

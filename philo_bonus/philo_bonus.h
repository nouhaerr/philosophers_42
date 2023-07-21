/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:50:02 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/07/21 22:50:00 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
#include <sys/types.h>
#include <signal.h>

typedef struct s_data
{
	int				nbr_of_ph;
	long			t_to_die;
	long long		t_to_eat;
	long long		t_to_sleep;
	struct timeval	start_time;
	int				t_of_each_ph_must_eat;
	sem_t			*ph_forks;
	sem_t			*status;
	sem_t			*check_die;
}	t_data;

typedef struct s_philo
{
	pthread_t		tid;
	pid_t			pid;
	int				ph_id;
	struct timeval	time_of_last_meal;
	sem_t			*forks;
	t_data			philo_inf;
}	t_philo;

int			_isdigit(int c);
long		ft_atol(const char *str);
int			is_empty(char **av);
int			check_args(char **av);
void		init_data(char **av, t_data *ph_info);
void		start_philos(t_philo *philo, t_data data);
void		*routine(void *arg);
void		take_forks(t_philo *philo);
int			is_eating(t_philo *philo);
void		is_sleeping(t_philo *philo);
void		is_thinking(t_philo *philo);
void		write_status(t_philo *philo, char *action);
long long	ft_gettime(void);
long long	ft_converttime(struct timeval time_now);
long long	time_stamp(long long time_stamp);
void		ft_usleep(long long time_sleep);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:15:47 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 20:58:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval	t_timeval;

typedef enum e_state
{
	INIT,
	CREATE_THREAD,
	MONITORING,
	JOIN_THREAD,
	ERROR,
	FINISH
}	t_state;

typedef enum e_fork_state
{
	RELEASE,
	HOLD
}	t_fork_state;

typedef struct s_fork
{
	t_fork_state	state;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_flag
{
	bool			state;
	pthread_mutex_t	mutex;
}	t_flag;

typedef struct s_dining_info
{
	uint64_t		last_dining_time;
	uint64_t		dining_count;
	pthread_mutex_t	mutex;
}	t_dining_info;

typedef struct s_rule
{
	uint64_t	number_of_philosophers;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	bool		required_meal_flag;
	uint64_t	required_meal_count;
}	t_rule;

typedef struct s_shared_data
{
	t_flag			break_flag;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	print_mutex;
	uint64_t		start_ms_time;
}	t_shared_data;

typedef struct s_philo
{
	uint64_t		number;
	t_rule			rule;
	t_shared_data	*shared_data;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_dining_info	dining_info;
}	t_philo;

typedef struct s_data
{
	t_rule			rule;
	t_shared_data	shared_data;
	t_fork			*fork_arr;
	t_philo			*philo_arr;
	pthread_t		*tid_arr;
}	t_data;

typedef enum e_dining_state
{
	PICKUP_LEFT_FORK,
	PICKUP_RIGHT_FORK,
	EAT,
	PUTDOWN_LEFT_FORK,
	PUTDOWN_RIGHT_FORK,
	GO_SLEEP,
	THINK,
	BREAK
}	t_dining_state;

typedef void			(*t_dining_routine_fp)(t_dining_state *dining_state, \
												t_philo *philo);

//init
void		init(t_state *state, t_data *data, int argc, char **argv);

//init_functions
void		init_rule(t_state *state, t_rule *rule, int argc, char **argv);
void		init_shared_data(t_state *state, t_shared_data *shared_data);
void		init_fork_arr(t_state *state, t_data *data);
void		init_philo_arr(t_state *state, t_data *data);
void		init_tid_arr(t_state *state, t_data *data);

//create_thread
void		create_thread(t_state *state, t_data *data);

//dining_routine
void		*dining_routine(void *_philo);

//dining_routine_functions
void		pickup_left_fork(t_dining_state *dining_state, t_philo *philo);
void		pickup_right_fork(t_dining_state *dining_state, t_philo *philo);
void		eat(t_dining_state *dining_state, t_philo *philo);
void		putdown_left_fork(t_dining_state *dining_state, t_philo *philo);
void		putdown_right_fork(t_dining_state *dining_state, t_philo *philo);
void		go_sleep(t_dining_state *dining_state, t_philo *philo);
void		think(t_dining_state *dining_state, t_philo *philo);

//monitoring
void		monitoring(t_state *state, t_data *data);

//join_thread
void		join_thread(t_state *state, t_data *data);

//error
void		error(t_state *state);

//utils
uint64_t	ascii_to_ull(t_state *state, const char *str);
void		*ft_malloc(t_state *state, uint64_t size);
int			ft_pthread_mutex_init(t_state *state, \
					pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
uint64_t	convert_to_ms_time(t_timeval time);
void		print_msg(t_philo *philo, uint64_t current_time, const char *msg);
void		ft_usleep(uint64_t start_ms_time, uint64_t millisecond);

#endif

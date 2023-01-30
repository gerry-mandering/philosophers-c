/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:07:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 20:51:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <sys/time.h>
# include <pthread.h>

// define fsm state
typedef enum e_state
{
	INIT_RULE,
	INIT_SHARED_RESOURCES,
	INIT_PHILO_ARR,
	CREATE_THREADS,
	MONITORING,
	JOIN_THREADS,
	CLEAR,
	FINISH,
	ERROR
}	t_state;

// define fork state
typedef enum e_fork_state
{
	RELEASE,
	HOLD
}	t_fork_state;

// define fork with state and mutex
typedef struct s_fork
{
	t_fork_state	state;
	pthread_mutex_t	mutex;
}	t_fork;

// define flag state
typedef enum e_flag_state
{
	OFF,
	ON
}	t_flag_state;

// define flag with state and mutex
typedef struct s_flag
{
	t_flag_state	state;
	pthread_mutex_t	mutex;
}	t_flag;

// define time with timevalue and mutex
typedef struct s_time
{
	struct timeval	value;
	pthread_mutex_t	mutex;
}	t_time;

// define count with count value and mutex
typedef struct s_count
{
	uint64_t		value;
	pthread_mutex_t	mutex;
}	t_count;

// define rule
typedef struct s_rule
{
	uint64_t		number_of_philosophers;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		required_number_of_meals;
	t_flag_state	required_number_of_meals_flag;
}	t_rule;

// define shared_resources
typedef struct s_shared_resources
{
	t_fork			*fork_arr;
	t_flag			start_flag;
	t_time			start_time;
	t_flag			dead_flag;
	t_count			finished_dining_count;
	pthread_mutex_t	printf_mutex;
}	t_shared_resources;

// define philo:thread
typedef struct t_philo
{
	t_rule				rule;
	t_shared_resources	*shared_resources;
	uint64_t			number;
	pthread_t			thread;
	struct timeval		last_dining_time;
	t_fork				*left_fork;
	t_fork				*right_fork;
}	t_philo;

typedef enum e_dining_routine_index
{
	PICKUP_FORK,
	EAT,
	PUTDOWN_FORK,
	GO_SLEEP,
	THINK
}	t_dining_routine_index;

typedef void	(*t_dining_routine_fp)(t_philo *philosopher);

// init_rule
void		init_rule(t_state *state, t_rule *rule, int argc, char **argv);

// init_shared_resources
void		init_shared_resources(t_state *state, t_rule *rule, \
										t_shared_resources *shared_resources);

// init_philo_arr
void		init_philo_arr(t_state *state, t_rule *rule, \
					t_shared_resources *shared_resources, t_philo **philo_arr);

// create_threads
void		create_threads(t_state *state, t_rule *rule, t_philo *philo_arr);
void		*dining_routine(void *philo);

// dining_routine_functions
void		pickup_fork(t_philo *philosopher);
void		putdown_fork(t_philo *philosopher);
void		eat(t_philo *philosopher);
void		go_sleep(t_philo *philosopher);
void		think(t_philo *philosopher);

// monitoring
void		monitoring(t_state *state, t_rule *rule, \
										t_shared_resources *shared_resources);
int			is_dead_flag_on(t_shared_resources *shared_resources);

// join_threads
void		join_threads(t_state *state, t_rule *rule, t_philo *philo_arr);

// clear
void		clear(t_state *state, t_rule *rule, \
					t_shared_resources *shared_resources, t_philo *philo_arr);

// error
void		error(t_state *state);

// utils
uint64_t	ascii_to_ull(t_state *state, const char *str);
void		print_message(uint64_t timestamp, uint64_t number, \
								const char *msg, pthread_mutex_t *printf_mutex);
uint64_t	get_ms_time(struct timeval time);
uint64_t	get_timestamp(struct timeval cur_time, t_time *start_time);
void		ft_usleep(uint64_t start_time, uint64_t usleep_time);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:09:54 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 20:19:23 by minseok2         ###   ########.fr       */
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

// define t_timeval
typedef struct timeval	t_timeval;

// define state
enum e_state
{
	INIT_RULE,
	INIT_SHARED_RESOURCE,
	INIT_PHILO_ARR,
	CREATE_THREAD,
	MONITORING,
	JOIN_THREAD,
	ERROR,
	FINISH
};

// define fork with mutex
enum e_fork_state
{
	RELEASE,
	HOLD
};

typedef struct s_fork
{
	enum e_fork_state	state;
	pthread_mutex_t		mutex;
}	t_fork;

// define flag with mutex
enum e_flag_state
{
	OFF,
	ON
};

typedef struct s_flag
{
	enum e_fork_state	state;
	pthread_mutex_t		mutex;
}	t_flag;

// define count with mutex
typedef struct s_count
{
	uint64_t		value;
	pthread_mutex_t	mutex;
}	t_count;

// define rule
typedef struct s_rule
{
	uint64_t			number_of_philosophers;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	enum e_flag_state	required_number_of_meals_flag;
	uint64_t			required_number_of_meals;
}	t_rule;

// define shared_resource
typedef struct s_shared_resource
{
	t_fork			*fork_arr;
	pthread_mutex_t	start_mutex;
	t_timeval		start_time;
	t_flag			dead_flag;
	t_count			finished_dining_count;
	pthread_mutex_t	msg_print_mutex;
}	t_shared_resource;

// define philo
typedef struct s_philo
{
	uint64_t			number;
	t_rule				rule;
	t_shared_resource	*shared_resource;
	t_timeval			last_dining_time;
	uint64_t			dining_count;
	t_fork				*left_fork;
	t_fork				*right_fork;
}	t_philo;

// define dining_routine_index
enum e_dining_state
{
	PICKUP_LEFT_FORK,
	PICKUP_RIGHT_FORK,
	EAT,
	PUTDOWN_LEFT_FORK,
	PUTDOWN_RIGHT_FORK,
	GO_SLEEP,
	THINK
};

// define dining_routine_fp
typedef int				(*t_dining_routine_fp)(t_philo *philo);

// init_rule
void		init_rule(enum e_state *state, t_rule *rule, int argc, char **argv);

// init_shared_resource
void		init_shared_resource(enum e_state *state, \
							t_rule *rule, t_shared_resource *shared_resource);

// init_philo_arr
void		init_philo_arr(enum e_state *state, \
		t_rule *rule, t_shared_resource *shared_resource, t_philo **philo_arr);

// create_thread
void		create_thread(enum e_state *state, \
						t_rule *rule, t_philo *philo_arr, pthread_t **tid_arr);

// dining_routine
void		*even_dining_routine(void *_philo);
void		*odd_dining_routine(void *_philo);

// dining_routine_functions
int			pickup_left_fork(t_philo *philo);
int			pickup_right_fork(t_philo *philo);
int			eat(t_philo *philo);
int			putdown_left_fork(t_philo *philo);
int			putdown_right_fork(t_philo *philo);
int			go_sleep(t_philo *philo);
int			think(t_philo *philo);

// dining_routine_utils
void		wait_for_dining_to_start(pthread_mutex_t *start_mutex);
int			is_dead_flag_on(t_shared_resource *shared_resource);
int			is_dining_finished(t_rule *rule, \
											t_shared_resource *shared_resource);
int			is_holding_fork(enum e_dining_state dining_state);
void		return_fork_back(enum e_dining_state dining_state, t_philo *philo);

// monitoring
void		monitoring(enum e_state *state, \
					t_rule *rule, t_shared_resource *shared_resource);

// join_thread
void		join_thread(enum e_state *state, t_rule *rule, pthread_t *tid_arr);

// error
void		error(enum e_state *state);

// utils
uint64_t	ascii_to_ull(enum e_state *state, const char *str);
void		*ft_malloc(enum e_state *state, size_t size);
int			ft_pthread_mutex_init(enum e_state *state, \
					pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

#endif

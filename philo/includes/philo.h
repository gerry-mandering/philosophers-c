/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:07:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/27 18:45:27 by minseok2         ###   ########.fr       */
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
	int				value;
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
	t_fork	*fork_arr;
	t_flag	start_flag;
	t_time	start_time;
	t_flag	dead_flag;
	t_count	finished_dining_count;
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

// init_rule
void		init_rule(t_state *state, t_rule *rule, int argc, char **argv);

// init_shared_resources
void		init_shared_resources(t_state *state, \
							t_shared_resources *shared_resources, t_rule *rule);

// init_philo_arr
void		init_philo_arr(t_state *state, t_philo **philo_arr, \
							t_shared_resources *shared_resources, t_rule *rule);

// create_threads

// monitoring

// join_threads

// clear

// error
void		error(t_state *state);

// utils
uint64_t	ascii_to_ull(t_state *state, const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:11:37 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 19:30:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_flag
{
	OFF,
	ON
}	t_flag;

typedef enum e_state
{
	INIT_SPEC,
	INIT_SHARED_RESOURCES,
	INIT_PHILOSOPHER_ARR,
	CREATE_THREADS,
	MONITORING,
	JOIN_THREADS,
	CLEAR,
	FINISH,
	ERROR
}	t_state;

typedef enum e_fork_state
{
	RELEASE,
	HOLD
}	t_fork_state;

typedef struct s_fork
{
	t_fork_state	fork_state;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_spec
{
	uint64_t	number_of_philosophers;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	number_of_meals;
}	t_spec;

typedef struct s_shared_resources
{
	t_fork			*fork_arr;
	t_flag			start_flag;
	struct timeval	start_time;
}	t_shared_resources;

typedef struct t_philosopher
{
	uint64_t	number;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philosopher;

// utils
uint64_t	ascii_to_ull(t_state *state, const char *str);

// init_spec
void		init_spec(t_state *state, t_spec *spec, int argc, char **argv);
void		init_number_of_philosophers(t_state *state, \
								uint64_t *number_of_philosophers, char *arg);
void		init_time_to_die(t_state *state, uint64_t *time_to_die, char *arg);
void		init_time_to_eat(t_state *state, uint64_t *time_to_eat, char *arg);
void		init_time_to_sleep(t_state *state, \
										uint64_t *time_to_sleep, char *arg);
void		init_number_of_meals(t_state *state, \
										uint64_t *number_of_meals, char *arg);

// init_forks
void		init_shared_resources(t_state *state, \
							t_spec *spec, t_shared_resources *shared_resources);

// init_philosopher_arr
void		init_philosopher_arr(t_state *state, t_spec *spec, \
		t_shared_resources *shared_resources, t_philosopher **philosopher_arr);

// create_threads
void		create_threads(t_state *state, t_spec *spec, \
		t_shared_resources *shared_resources, t_philosopher *philosopher_arr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:11:37 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/26 23:51:42 by minseok2         ###   ########.fr       */
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

# define SUCCESS	0

# define ON		1
# define OFF	0

typedef enum e_state
{
	INIT_RULE,
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
	t_fork_state	state;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_flag
{
	int				flag;
	pthread_mutex_t	mutex;
}	t_flag;

typedef struct s_time
{
	struct timeval	time;
	pthread_mutex_t	mutex;
}	t_time;

typedef struct s_finish_dinner_count
{
	uint64_t		finish_dinner_count;
	pthread_mutex_t	mutex;
}	t_finish_dinner_count;

typedef struct s_rule
{
	uint64_t	number_of_philosophers;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	number_of_meals;
	int			number_of_meals_flag;
}	t_rule;

typedef struct s_shared_resources
{
	t_fork					*fork_arr;
	t_finish_dinner_count	finish_dinner_count;
	t_flag					start_flag;
	t_time					start_time;
	t_flag					dead_flag;
}	t_shared_resources;

typedef struct t_philosopher
{
	t_rule					rule;
	pthread_t				thread;
	uint64_t				number;
	t_finish_dinner_count	*finish_dinner_count;
	t_flag					*start_flag;
	t_time					*start_time;
	t_time					last_dinner_time;
	t_flag					*dead_flag;
	t_fork					*left_fork;
	t_fork					*right_fork;
}	t_philosopher;

// utils
uint64_t	ascii_to_ull(t_state *state, const char *str);

// init_rule
void		init_rule(t_state *state, t_rule *rule, int argc, char **argv);
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
							t_rule *rule, t_shared_resources *shared_resources);

// init_philosopher_arr
void		init_philosopher_arr(t_state *state, t_rule *rule, \
		t_shared_resources *shared_resources, t_philosopher **philosopher_arr);

// create_threads
void		create_threads(t_state *state, t_rule *rule, \
		t_shared_resources *shared_resources, t_philosopher *philosopher_arr);

// monitoring
void		monitoring(t_state *state, t_rule *rule, \
		t_shared_resources *shared_resources, t_philosopher *philosopher_arr);

// join_thread
void		join_thread(t_state *state, t_rule *rule, \
												t_philosopher *philosopher_arr);

// error
void	error(t_state *state);

#endif

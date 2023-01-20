/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:10:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/20 18:35:49 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <sys/_types/_timeval.h>

struct timeval	calculate_time_diff(struct timeval current_time, struct timeval st)

void	print_timestamp(struct timeval start_time, struct timeval current_time, \
		char *number_string, const char *message)
{

}

void	pickup_fork(const t_philosopher *philo)
{
	struct timeval	current_time;
	struct timeval	fork_pickup_time;

	pthread_mutex_lock(&(*philo).left_fork->fork_mutex);
	(*philo).left_fork->state = HOLD;
	pthread_mutex_lock(&(*philo).right_fork->fork_mutex);
	(*philo).right_fork->state = HOLD;
	gettimeofday(&current_time, NULL);
	fork_pickup_time = calculate_time_diff(current_time, (*philo).start_time);
	print_timestamp((*philo).start_time, fork_pickup_time, (*philo).number_string, "has taken a fork");
}

void	put_fork_down(const t_philosopher *philo)
{
	(*philo).left_fork->state = RELEASE;
	pthread_mutex_unlock(&(*philo).left_fork->fork_mutex);
	(*philo).right_fork->state = RELEASE;
	pthread_mutex_unlock(&(*philo).right_fork->fork_mutex);
}

void	eat(const t_philosopher *philo)
{
	usleep((*philo).rule.time_to_eat);
}

void	*dinning_routine(void *philosopher)
{
	const t_philosopher	philo = *((t_philosopher *)philosopher);

	pthread_mutex_lock(&philo.start_flag->mutex);
	while (philo.start_flag->flag != ON)
		;
	pthread_mutex_unlock(&philo.start_flag->mutex);
	while (1)
	{
		pthread_mutex_lock(&philo.dead_flag->mutex);
		if (philo.dead_flag->flag == ON)
		{
			pthread_mutex_unlock(&philo.dead_flag->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo.dead_flag->mutex);
		pickup_fork(&philo);
		eat(&philo);
		put_fork_down(&philo);
		usleep(philo.rule.time_to_sleep);
		think(&philo);
	}
	return (NULL);
}

void	create_threads(t_state *state, t_rule *rule, \
		t_shared_resources *shared_resources, t_philosopher *philosopher_arr)
{
	uint64_t	i;
	int			result;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		result = pthread_create(&philosopher_arr[i].thread, NULL, \
										dinning_routine, &philosopher_arr[i]);
		if (result != SUCCESS)
		{
			*state = ERROR;
			return ;
		}
		i++;
	}
	*state = MONITORING;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 17:00:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <pthread.h>

static void	wait_for_dining_start(t_shared_resources *shared_resources)
{
	while (1)
	{
		pthread_mutex_lock(&shared_resources->start_flag.mutex);
		if (shared_resources->start_flag.state == ON)
		{
			pthread_mutex_unlock(&shared_resources->start_flag.mutex);
			break ;
		}
		pthread_mutex_unlock(&shared_resources->start_flag.mutex);
	}
}

static void	init_last_dining_time(t_philo *philosopher, \
										t_shared_resources *shared_resources)
{
	pthread_mutex_lock(&shared_resources->start_time.mutex);
	philosopher->last_dining_time = shared_resources->start_time.value;
	pthread_mutex_unlock(&shared_resources->start_time.mutex);
}

static void	raise_dead_flag(t_shared_resources *shared_resources)
{
	pthread_mutex_lock(&shared_resources->dead_flag.mutex);
	shared_resources->dead_flag.state = ON;
	pthread_mutex_unlock(&shared_resources->dead_flag.mutex);
}

static int	is_philosopher_dead(t_philo *philosopher, \
		t_shared_resources *shared_resources, t_dining_routine_index fp_index)
{
	const struct timeval	last_dining_time = philosopher->last_dining_time;
	struct timeval			cur_time;
	uint64_t				time_diff;

	gettimeofday(&cur_time, NULL);
	time_diff = ((cur_time.tv_sec - last_dining_time.tv_sec) * 1000) + \
				((cur_time.tv_usec - last_dining_time.tv_usec) / 1000);
	//testcode
	//pthread_mutex_lock(&shared_resources->printf_mutex);
	//printf("((%ld - %ld) * 1000) + ((%d - %d) / 1000) = %lld\n", cur_time.tv_sec, last_dining_time.tv_sec, cur_time.tv_usec, last_dining_time.tv_usec, time_diff);
	//printf("time diff = %lld\n", time_diff);
	//pthread_mutex_unlock(&shared_resources->printf_mutex);
	if (time_diff > philosopher->rule.time_to_die)
	{
		raise_dead_flag(shared_resources);
		print_message(get_timestamp(cur_time, &shared_resources->start_time), \
				philosopher->number, "died", &shared_resources->printf_mutex);
		return (1);
	}
	else
		return (0);
}

void	*dining_routine(void *philo)
{
	t_philo						*philosopher;
	t_dining_routine_index		fp_index;
	const t_dining_routine_fp	dining_routine_fp[5] = {
		pickup_fork, eat, putdown_fork, go_sleep, think
	};

	philosopher = (t_philo *)philo;
	wait_for_dining_start(philosopher->shared_resources);
	init_last_dining_time(philosopher, philosopher->shared_resources);
	fp_index = PICKUP_FORK;
	while (1)
	{
		if (is_dead_flag_on(philosopher->shared_resources) || \
	is_philosopher_dead(philosopher, philosopher->shared_resources, fp_index))
		{
			if (fp_index == EAT || fp_index == PUTDOWN_FORK)
				putdown_fork(philosopher);
			//pthread_mutex_lock(&philosopher->shared_resources->printf_mutex);
			//printf("<%lld break ;>\n", philosopher->number);
			//pthread_mutex_unlock(&philosopher->shared_resources->printf_mutex);
			break ;
		}
		dining_routine_fp[fp_index](philosopher);
		if (fp_index == THINK)
			fp_index = PICKUP_FORK;
		else
			fp_index++;
	}
	return (NULL);
}

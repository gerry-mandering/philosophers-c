/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:10:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/21 17:54:14 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	calculate_time_diff(struct timeval start_time, \
													struct timeval current_time)
{
	long	diff_time;


	diff_time = ((current_time.tv_sec - start_time.tv_sec) * 1000) + \
				((current_time.tv_usec - start_time.tv_usec) / 1000);
	printf("((current_time.tv_sec - start_time.tv_sec) * 1000) + ((current_time.tv_usec - start_time.tv_usec) / 1000) = %ld - %ld * 1000 + %d - %d / 1000 = %ld", current_time.tv_sec, start_time.tv_sec, current_time.tv_usec, current_time.tv_usec, diff_time);
	return (diff_time);
}

void	print_timestamp(long current_time, uint64_t number, \
														const char *message)
{
	printf("%ld %lld %s\n", current_time, number, message);
}

void	pickup_fork(t_philosopher *philo)
{
	struct timeval	current_time;
	long			fork_pickup_time;

	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	philo->left_fork->state = HOLD;
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	philo->right_fork->state = HOLD;
	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&philo->start_time->mutex);
	fork_pickup_time = calculate_time_diff(philo->start_time->time, current_time);
	pthread_mutex_unlock(&philo->start_time->mutex);
	print_timestamp(fork_pickup_time, philo->number, "has taken a fork");
}

void	put_fork_down(t_philosopher *philo)
{
	philo->left_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
}

void	eat(t_philosopher *philo)
{
	struct timeval	current_time;
	long			eat_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&philo->start_time->mutex);
	eat_time = calculate_time_diff(philo->start_time->time, current_time);
	pthread_mutex_unlock(&philo->start_time->mutex);
	print_timestamp(eat_time, philo->number, "is eating");
	usleep(philo->rule.time_to_eat);
}

void	go_sleep(t_philosopher *philo)
{
	struct timeval	current_time;
	long			go_sleep_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&philo->start_time->mutex);
	go_sleep_time = calculate_time_diff(philo->start_time->time, current_time);
	pthread_mutex_unlock(&philo->start_time->mutex);
	print_timestamp(go_sleep_time, philo->number, "is sleeping");
	usleep(philo->rule.time_to_sleep);
}

void	think(t_philosopher *philo)
{
	struct timeval	current_time;
	long			think_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&philo->start_time->mutex);
	think_time = calculate_time_diff(philo->start_time->time, current_time);
	pthread_mutex_unlock(&philo->start_time->mutex);
	print_timestamp(think_time, philo->number, "is thinking");
}

void	*dinning_routine(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	pthread_mutex_lock(&philo->start_flag->mutex);
	while (philo->start_flag->flag != ON)
		;
	pthread_mutex_unlock(&philo->start_flag->mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->dead_flag->mutex);
		if (philo->dead_flag->flag == ON)
		{
			pthread_mutex_unlock(&philo->dead_flag->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->dead_flag->mutex);
		pickup_fork(philo);
		eat(philo);
		put_fork_down(philo);
		go_sleep(philo);
		think(philo);
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

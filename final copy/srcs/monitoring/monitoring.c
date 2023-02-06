/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:14:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 06:09:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <stdint.h>

static void	raise_break_flag(t_shared_data *shared_data)
{
	//pthread_mutex_lock(&shared_data->break_flag.mutex);
	shared_data->break_flag.state = true;
	//pthread_mutex_unlock(&shared_data->break_flag.mutex);
}

static bool	is_philosopher_dead(t_rule *rule, t_philo *philo)
{
	t_timeval	current_time;
	uint64_t	current_ms_time;
	uint64_t	time_diff;

	gettimeofday(&current_time, NULL);
	current_ms_time = convert_to_ms_time(current_time);
	pthread_mutex_lock(&philo->dining_info.mutex);
	time_diff = current_ms_time - philo->dining_info.last_dining_time;
	if (time_diff > rule->time_to_die)
	{
		pthread_mutex_unlock(&philo->dining_info.mutex);
		pthread_mutex_lock(&philo->shared_data->break_flag.mutex);
		print_msg(philo, current_ms_time, "died");
		philo->shared_data->break_flag.state = true;
		pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
		return (true);
	}
	if (rule->required_meal_flag == false)
		pthread_mutex_unlock(&philo->dining_info.mutex);
	return (false);
}

static bool	is_dining_finished(t_rule *rule, t_philo *philo, uint64_t *dining_finished_philosopher_count)
{
	if (rule->required_meal_flag == false)
		return (false);
	if (philo->dining_info.dining_count == rule->required_meal_count)
		(*dining_finished_philosopher_count)++;
	if (*dining_finished_philosopher_count == rule->number_of_philosophers)
	{
		printf("dining_finished_philosopher_count = %llu\n", *dining_finished_philosopher_count);
		//pthread_mutex_unlock(&philo->dining_info.mutex);
		raise_break_flag(philo->shared_data);
		pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
		return (true);
	}
	//pthread_mutex_unlock(&philo->dining_info.mutex);
	pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
	return (false);
}

void	monitoring(t_state *state, t_data *data)
{
	t_philo		*philo_arr;
	t_rule		*rule;
	uint64_t	i;
	t_timeval	current_time;
	uint64_t	dining_finished_philosopher_count;

	philo_arr = data->philo_arr;
	rule = &data->rule;
	i = 0;
	dining_finished_philosopher_count = 0;
	gettimeofday(&current_time, NULL);
	ft_usleep(convert_to_ms_time(current_time), data->rule.time_to_die * 0.7);
	while (!is_philosopher_dead(rule, &philo_arr[i]) && \
				!is_dining_finished(rule, &philo_arr[i], &dining_finished_philosopher_count))
	{
		if (i == data->rule.number_of_philosophers - 1)
		{
			i = 0;
			dining_finished_philosopher_count = 0;
			gettimeofday(&current_time, NULL);
			ft_usleep(convert_to_ms_time(current_time), 7);
		}
		else
			i++;
	}
	*state = JOIN_THREAD;
}

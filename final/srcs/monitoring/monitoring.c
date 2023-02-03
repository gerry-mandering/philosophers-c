/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:14:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 21:57:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	raise_break_flag(t_shared_data *shared_data)
{
	pthread_mutex_lock(&shared_data->break_flag.mutex);
	shared_data->break_flag.state = true;
	pthread_mutex_unlock(&shared_data->break_flag.mutex);
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
		raise_break_flag(philo->shared_data);
		print_msg(philo, current_ms_time, "died");
		pthread_mutex_unlock(&philo->dining_info.mutex);
		return (true);
	}
	if (rule->required_meal_flag == false)
		pthread_mutex_unlock(&philo->dining_info.mutex);
	return (false);
}

static bool	is_dining_finished(t_rule *rule, t_philo *philo)
{
	static uint64_t	dining_finished_philosopher_count;

	if (rule->required_meal_flag == false)
		return (false);
	if (philo->dining_info.dining_count == rule->required_meal_count)
		dining_finished_philosopher_count++;
	if (dining_finished_philosopher_count == rule->number_of_philosophers)
	{
		raise_break_flag(philo->shared_data);
		pthread_mutex_unlock(&philo->dining_info.mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->dining_info.mutex);
	return (false);
}

void	monitoring(t_state *state, t_data *data)
{
	t_philo		*philo_arr;
	t_rule		*rule;
	uint64_t	i;

	philo_arr = data->philo_arr;
	rule = &data->rule;
	i = 0;
	while (!is_philosopher_dead(rule, &philo_arr[i]) && \
				!is_dining_finished(rule, &philo_arr[i]))
	{
		if (i == data->rule.number_of_philosophers - 1)
			i = 0;
		else
			i++;
	}
	*state = JOIN_THREAD;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:03:45 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 18:07:38 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static bool	is_philo_died(t_rule rule, t_philo *philo_arr, t_flag *break_flag)
{
	uint64_t	dining_term;
	uint64_t	i;

	i = 0;
	while (i < rule.number_of_philosophers)
	{
		pthread_mutex_lock(&philo_arr[i].dining_time.mutex);
		dining_term = get_current_time() - philo_arr[i].dining_time.value;
		pthread_mutex_unlock(&philo_arr[i].dining_time.mutex);
		if (dining_term > rule.time_to_die)
		{
			pthread_mutex_lock(&break_flag->mutex);
			break_flag->state = true;
			print_msg(&philo_arr[i], get_current_time(), "died");
			pthread_mutex_unlock(&break_flag->mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	is_dining_finished(t_rule rule, \
								t_philo *philo_arr, t_flag *break_flag)
{
	uint64_t	dining_finished_philo_count;
	uint64_t	i;

	dining_finished_philo_count = 0;
	i = 0;
	while (i < rule.number_of_philosophers)
	{
		pthread_mutex_lock(&philo_arr[i].dining_count.mutex);
		if (philo_arr[i].dining_count.value >= rule.required_meal_count)
			dining_finished_philo_count++;
		pthread_mutex_unlock(&philo_arr[i].dining_count.mutex);
		i++;
	}
	if (dining_finished_philo_count == rule.number_of_philosophers)
	{
		pthread_mutex_lock(&break_flag->mutex);
		break_flag->state = true;
		pthread_mutex_unlock(&break_flag->mutex);
		return (true);
	}
	return (false);
}

void	monitoring(t_state *state, t_data *data)
{
	ft_usleep(get_current_time(), data->rule.time_to_die * 0.7);
	while (true)
	{
		if (is_philo_died(data->rule, data->philo_arr, &data->break_flag))
			break ;
		else if (data->rule.required_meal_flag && \
			is_dining_finished(data->rule, data->philo_arr, &data->break_flag))
			break ;
	}
	*state = JOIN_THREAD;
}

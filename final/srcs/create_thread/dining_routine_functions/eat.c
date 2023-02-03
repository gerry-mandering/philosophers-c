/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:31:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 22:02:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

static void	update_dining_info(t_philo *philo, t_timeval current_time)
{
	pthread_mutex_lock(&philo->dining_info.mutex);
	philo->dining_info.last_dining_time = convert_to_ms_time(current_time);
	if (philo->rule.required_meal_flag == true)
		philo->dining_info.dining_count++;
	pthread_mutex_unlock(&philo->dining_info.mutex);
}

void	eat(t_dining_state *dining_state, t_philo *philo)
{
	t_timeval	current_time;

	pthread_mutex_lock(&philo->shared_data->break_flag.mutex);
	if (philo->shared_data->break_flag.state == true)
	{
		pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
		*dining_state = BREAK;
		return ;
	}
	gettimeofday(&current_time, NULL);
	print_msg(philo, convert_to_ms_time(current_time), "is eating");
	update_dining_info(philo, current_time);
	pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
	ft_usleep(convert_to_ms_time(current_time), philo->rule.time_to_eat);
	*dining_state = PUTDOWN_LEFT_FORK;
}

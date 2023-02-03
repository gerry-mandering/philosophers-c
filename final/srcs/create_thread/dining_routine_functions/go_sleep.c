/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:50:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 22:02:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	go_sleep(t_dining_state *dining_state, t_philo *philo)
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
	print_msg(philo, convert_to_ms_time(current_time), "is sleeping");
	pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
	ft_usleep(convert_to_ms_time(current_time), philo->rule.time_to_sleep);
	*dining_state = THINK;
}

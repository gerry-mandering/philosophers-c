/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:36:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:45:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	go_sleep(t_dining_state *dining_state, t_philo *philo)
{
	uint64_t	current_time;

	if (is_break_flag_on(philo->break_flag))
	{
		*dining_state = FINISH_DINING;
		return ;
	}
	else
	{
		current_time = get_current_time();
		print_msg(philo, current_time, "is sleeping");
		pthread_mutex_unlock(&philo->break_flag->mutex);
		ft_usleep(current_time, philo->rule.time_to_sleep);
		*dining_state = THINK;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:14:21 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 19:28:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	eat(t_philo *philo)
{
	t_timeval			current_time;
	enum e_flag_state	break_flag;

	pthread_mutex_lock(&philo->shared_resource->msg_print_mutex);
	gettimeofday(&current_time, NULL);
	if (is_dead_flag_on(philo->shared_resource) || \
			is_dining_finished(&philo->rule, philo->shared_resource))
		break_flag = ON;
	else if (is_philosopher_dead(philo, current_time))
	{
		raise_dead_flag(philo, current_time);
		break_flag = ON;
	}
	else
	{
		//위로 순서 변경해보기
		break_flag = OFF;
		print_msg(philo, current_time, "is eating");
		philo->last_dining_time = current_time;
	}
	pthread_mutex_unlock(&philo->shared_resource->msg_print_mutex);
	ft_usleep(current_time, philo->rule.time_to_eat);
	return (break_flag);
}

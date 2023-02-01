/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup_left_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:14:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 20:34:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	pickup_left_fork(t_philo *philo)
{
	t_timeval			current_time;
	enum e_flag_state	break_flag;

	pthread_mutex_lock(&philo->shared_resource->msg_print_mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->state = HOLD;
	gettimeofday(&current_time, NULL);
	if (is_philosopher_dead(philo, &current_time))
	{
		raise_dead_flag(philo, &current_time);
		break_flag = ON;
	}
	else if (is_dead_flag_on(philo->shared_resource) || \
			is_dining_finished(&philo->rule, philo->shared_resource))
		break_flag = ON;
	else
	{
		break_flag = OFF;
		print_msg(philo, &current_time, "has taken a fork");
	}
	pthread_mutex_unlock(&philo->shared_resource->msg_print_mutex);
	return (break_flag);
}

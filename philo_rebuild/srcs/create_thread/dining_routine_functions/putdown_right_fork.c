/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdown_right_fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:38:33 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 19:27:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	putdown_right_fork(t_philo *philo)
{
	t_timeval			current_time;
	enum e_flag_state	break_flag;

	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	gettimeofday(&current_time, NULL);
	if (is_philosopher_dead(philo, current_time))
	{
		raise_dead_flag(philo, current_time);
		break_flag = ON;
	}
	else if (is_dead_flag_on(philo->shared_resource) || \
			is_dining_finished(&philo->rule, philo->shared_resource))
		break_flag = ON;
	else
	{
		//위로 순서 변경해보기
		break_flag = OFF;
	}
	return (break_flag);
}

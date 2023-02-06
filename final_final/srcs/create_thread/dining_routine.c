/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:44:02 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 15:52:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	waiting_for_start(pthread_mutex_t *start_mutex)
{
	pthread_mutex_lock(start_mutex);
	pthread_mutex_unlock(start_mutex);
}

void	*dining_routine(void *_philo)
{
	const t_dining_routine_fp	dining_routine_fp[7] = {
		pickup_left_fork, pickup_right_fork, eat, \
		putdown_left_fork, putdown_right_fork, go_sleep, think
	};
	t_dining_state				dining_state;
	t_philo						*philo;

	philo = _philo;
	waiting_for_start(philo->start_mutex);
	if (philo->number % 2 == 0)
		ft_usleep(get_current_time(), philo->rule.time_to_eat * 0.7);
	dining_state = PICKUP_LEFT_FORK;
	while (1)
	{
		dining_routine_fp[dining_state](&dining_state, philo);
		if (dining_state == FINISH_DINING)
			break ;
	}
	return (NULL);
}

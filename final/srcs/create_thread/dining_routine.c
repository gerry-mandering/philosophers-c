/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:59:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 21:58:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*dining_routine(void *_philo)
{
	t_philo						*philo;
	const t_dining_routine_fp	dining_routine_fp[7] = {
		pickup_left_fork, pickup_right_fork, eat, \
		putdown_left_fork, putdown_right_fork, go_sleep, think
	};
	t_dining_state				dining_state;

	philo = _philo;
	pthread_mutex_lock(&philo->shared_data->start_mutex);
	pthread_mutex_unlock(&philo->shared_data->start_mutex);
	if (philo->number % 2)
		usleep(1000);
	dining_state = PICKUP_LEFT_FORK;
	while (dining_state != BREAK)
		dining_routine_fp[dining_state](&dining_state, philo);
	return (NULL);
}

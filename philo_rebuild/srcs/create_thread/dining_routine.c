/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:27:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 20:16:40 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	init(t_philo *philo, \
			enum e_dining_state *dining_state, enum e_flag_state *break_flag);

void	*even_dining_routine(void *_philo)
{
	const t_dining_routine_fp	dining_routine_fp[7] = {
		pickup_left_fork, pickup_right_fork, eat, \
		putdown_left_fork, putdown_right_fork, go_sleep, think
	};
	enum e_dining_state			dining_state;
	enum e_flag_state			break_flag;
	t_philo						*philo;

	philo = (t_philo *)_philo;
	wait_for_dining_to_start(&philo->shared_resource->start_mutex);
	init(philo, &dining_state, &break_flag);
	while (1)
	{
		break_flag = dining_routine_fp[dining_state](philo);
		if (break_flag == ON)
			break ;
		if (dining_state == THINK)
			dining_state = PICKUP_LEFT_FORK;
		else
			dining_state++;
	}
	if (is_holding_fork(dining_state))
		return_fork_back(dining_state, philo);
	return (NULL);
}

void	*odd_dining_routine(void *_philo)
{
	const t_dining_routine_fp	dining_routine_fp[7] = {
		pickup_left_fork, pickup_right_fork, eat, \
		putdown_left_fork, putdown_right_fork, go_sleep, think
	};
	enum e_dining_state			dining_state;
	enum e_flag_state			break_flag;
	t_philo						*philo;

	philo = (t_philo *)_philo;
	wait_for_dining_to_start(&philo->shared_resource->start_mutex);
	init(philo, &dining_state, &break_flag);
	usleep(100);
	while (1)
	{
		break_flag = dining_routine_fp[dining_state](philo);
		if (break_flag == ON)
			break ;
		if (dining_state == THINK)
			dining_state = PICKUP_LEFT_FORK;
		else
			dining_state++;
	}
	if (is_holding_fork(dining_state))
		return_fork_back(dining_state, philo);
	return (NULL);
}

static void	init(t_philo *philo, \
			enum e_dining_state *dining_state, enum e_flag_state *break_flag)
{
	philo->last_dining_time = philo->shared_resource->start_time;
	*dining_state = PICKUP_LEFT_FORK;
	*break_flag = OFF;
}

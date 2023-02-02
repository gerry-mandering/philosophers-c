/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:33:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 20:54:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// function declaration
static void	start_dining(t_timeval *start_time, pthread_mutex_t *start_mutex);

void	monitoring(enum e_state *state, \
					t_rule *rule, t_shared_resource *shared_resource)
{
	start_dining(&shared_resource->start_time, &shared_resource->start_mutex);
	while (1)
	{
		if (is_dead_flag_on(shared_resource))
			break ;
		if (rule->required_number_of_meals_flag == ON && \
			is_dining_finished(rule, shared_resource))
			break ;
		usleep(1000);
	}
	*state = JOIN_THREAD;
}

static void	start_dining(t_timeval *start_time, pthread_mutex_t *start_mutex)
{
	gettimeofday(start_time, NULL);
	pthread_mutex_unlock(start_mutex);
}

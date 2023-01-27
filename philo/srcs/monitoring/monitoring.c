/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:45:54 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/27 20:43:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	start_dining(t_shared_resources *shared_resources)
{
	pthread_mutex_lock(&shared_resources->start_flag.mutex);
	shared_resources->start_flag.state = ON;
	pthread_mutex_unlock(&shared_resources->start_flag.mutex);
}

int	is_dead_flag_on(t_shared_resources *shared_resources)
{
	t_flag_state	flag;

	pthread_mutex_lock(&shared_resources->dead_flag.mutex);
	if (shared_resources->dead_flag.state == ON)
		flag = ON;
	else
		flag = OFF;
	pthread_mutex_unlock(&shared_resources->dead_flag.mutex);
	return (flag);
}

int	is_dining_finished(t_rule *rule, t_shared_resources *shared_resources)
{
	
}

void	monitoring(t_state *state, t_rule *rule, \
										t_shared_resources *shared_resources)
{
	start_dining(shared_resources);
	while (1)
	{
		if (is_dead_flag_on(shared_resources) || \
									is_dining_finished(rule, shared_resources))
			break ;
	}
	*state = JOIN_THREADS;
}

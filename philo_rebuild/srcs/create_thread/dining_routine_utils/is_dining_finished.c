/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dining_finished.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:35:19 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 19:53:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	is_dining_finished(t_rule *rule, t_shared_resource *shared_resource)
{
	t_count	*finished_dining_count;

	finished_dining_count = &shared_resource->finished_dining_count;
	pthread_mutex_lock(&finished_dining_count->mutex);
	if (finished_dining_count->value == rule->number_of_philosophers)
	{
		pthread_mutex_unlock(&finished_dining_count->mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&finished_dining_count->mutex);
		return (0);
	}
}

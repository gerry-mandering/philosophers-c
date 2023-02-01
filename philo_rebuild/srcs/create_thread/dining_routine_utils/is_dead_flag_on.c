/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_flag_on.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:15 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 19:22:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	is_dead_flag_on(t_shared_resource *shared_resource)
{
	pthread_mutex_lock(&shared_resource->dead_flag.mutex);
	if (shared_resource->dead_flag.state == ON)
	{
		pthread_mutex_unlock(&shared_resource->dead_flag.mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&shared_resource->dead_flag.mutex);
		return (0);
	}
}

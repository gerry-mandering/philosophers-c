/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_dining_to_start.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 18:55:14 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	wait_for_dining_to_start(t_shared_resource *shared_resource)
{
	pthread_mutex_lock(&shared_resource->start_mutex);
	pthread_mutex_unlock(&shared_resource->start_mutex);
}

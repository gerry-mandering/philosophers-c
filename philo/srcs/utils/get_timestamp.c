/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:49:43 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 20:42:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

uint64_t	get_timestamp(struct timeval cur_time, t_time *start_time)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&start_time->mutex);
	timestamp = get_ms_time(cur_time) - get_ms_time(start_time->value);
	pthread_mutex_unlock(&start_time->mutex);
	return (timestamp);
}

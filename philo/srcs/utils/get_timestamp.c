/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:49:43 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 13:59:07 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

uint64_t	get_timestamp(struct timeval cur_time, t_time *start_time)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&start_time->mutex);
	timestamp = ((cur_time.tv_sec - start_time->value.tv_sec) * 1000) + \
				((cur_time.tv_usec - start_time->value.tv_usec) / 1000);
	pthread_mutex_unlock(&start_time->mutex);
	return (timestamp);
}

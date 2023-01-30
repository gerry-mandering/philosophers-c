/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ms_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:40:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 20:42:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

uint64_t	get_ms_time(struct timeval time)
{
	uint64_t	ms_time;

	ms_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms_time);
}

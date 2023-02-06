/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_ms_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:59:36 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 20:00:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

uint64_t	convert_to_ms_time(t_timeval time)
{
	uint64_t	millisecond;

	millisecond = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (millisecond);
}

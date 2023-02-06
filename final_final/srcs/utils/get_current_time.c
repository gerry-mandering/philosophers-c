/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:48:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 09:53:02 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

uint64_t	get_current_time(void)
{
	t_timeval	current_time;
	uint64_t	millisecond;

	gettimeofday(&current_time, NULL);
	millisecond = convert_to_ms_time(current_time);
	return (millisecond);
}

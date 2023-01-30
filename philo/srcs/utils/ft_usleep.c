/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:36:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 20:50:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static uint64_t	get_cur_ms_time(void)
{
	struct timeval	cur_time;
	uint64_t		cur_ms_time;

	gettimeofday(&cur_time, NULL);
	cur_ms_time = get_ms_time(cur_time);
	return (cur_ms_time);
}

void	ft_usleep(uint64_t start_time, uint64_t usleep_time)
{
	uint64_t	time_limit;

	time_limit = start_time + usleep_time;
	while (get_cur_ms_time() < time_limit)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:08:19 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/05 20:24:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_usleep(uint64_t start_ms_time, uint64_t millisecond)
{
	t_timeval	current_time;
	uint64_t	current_ms_time;
	uint64_t	end_time;

	end_time = start_ms_time + millisecond;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		current_ms_time = convert_to_ms_time(current_time);
		if (current_ms_time > end_time)
			break ;
		if (current_ms_time < start_ms_time + (millisecond * 0.9))
			usleep(300);
	}
}

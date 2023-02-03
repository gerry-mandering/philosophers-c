/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:37:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 14:26:25 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	ft_usleep(t_timeval start_time, uint64_t millisecond)
{
	uint64_t	start_ms_time;
	uint64_t	usleep_time_limit;
	uint64_t	busywait_time_limit;
	t_timeval	current_time;

	start_ms_time = convert_to_ms(start_time);
	usleep_time_limit = start_ms_time + (millisecond * 0.9);
	busywait_time_limit = start_ms_time + millisecond;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		if (convert_to_ms(current_time) > usleep_time_limit)
			break ;
		usleep(1000);
	}
	while (1)
	{
		gettimeofday(&current_time, NULL);
		if (convert_to_ms(current_time) > busywait_time_limit)
			break ;
	}
}

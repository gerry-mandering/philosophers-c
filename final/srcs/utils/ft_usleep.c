/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:08:19 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 20:14:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_usleep(uint64_t start_ms_time, uint64_t millisecond)
{
	uint64_t	end_time;
	t_timeval	current_time;

	end_time = start_ms_time + millisecond;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		if (convert_to_ms_time(current_time) > end_time)
			break ;
		usleep(300);
	}
}

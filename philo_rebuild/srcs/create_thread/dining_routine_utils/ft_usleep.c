/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:37:42 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:12 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	ft_usleep(t_timeval start_time, uint64_t millisecond)
{
	uint64_t	time_limit;
	t_timeval	current_time;

	time_limit = convert_to_ms(start_time) + millisecond;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		if (convert_to_ms(current_time) > time_limit)
			break ;
		usleep(200);
	}
}

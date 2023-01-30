/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 20:52:42 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	eat(t_philo *philosopher)
{
	t_shared_resources	*shared_resources;
	struct timeval		cur_time;

	shared_resources = philosopher->shared_resources;
	gettimeofday(&cur_time, NULL);
	philosopher->last_dining_time = cur_time;
	print_message(get_timestamp(cur_time, &shared_resources->start_time), \
			philosopher->number, "is eating", &shared_resources->printf_mutex);
	ft_usleep(get_ms_time(cur_time), philosopher->rule.time_to_eat);
}

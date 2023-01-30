/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 16:03:18 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

static void	set_last_dining_time(t_philo *philosopher)
{
	struct timeval		last_dining_time;

	gettimeofday(&last_dining_time, NULL);
	philosopher->last_dining_time = last_dining_time;
}

void	eat(t_philo *philosopher)
{
	t_shared_resources	*shared_resources;
	struct timeval		cur_time;

	shared_resources = philosopher->shared_resources;
	gettimeofday(&cur_time, NULL);
	print_message(get_timestamp(cur_time, &shared_resources->start_time), \
			philosopher->number, "is eating", &shared_resources->printf_mutex);
	usleep(philosopher->rule.time_to_eat * 1000);
	set_last_dining_time(philosopher);
}

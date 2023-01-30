/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:31 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 16:03:29 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	go_sleep(t_philo *philosopher)
{
	t_shared_resources	*shared_resources;
	struct timeval		cur_time;

	shared_resources = philosopher->shared_resources;
	gettimeofday(&cur_time, NULL);
	print_message(get_timestamp(cur_time, &shared_resources->start_time), \
		philosopher->number, "is sleeping", &shared_resources->printf_mutex);
	usleep(philosopher->rule.time_to_sleep * 1000);
}

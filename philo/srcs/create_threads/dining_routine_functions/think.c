/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:39:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 15:32:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	think(t_philo *philosopher)
{
	t_shared_resources	*shared_resources;
	struct timeval		cur_time;

	shared_resources = philosopher->shared_resources;
	gettimeofday(&cur_time, NULL);
	print_message(get_timestamp(cur_time, &shared_resources->start_time), \
		philosopher->number, "is thinking", &shared_resources->printf_mutex);
}

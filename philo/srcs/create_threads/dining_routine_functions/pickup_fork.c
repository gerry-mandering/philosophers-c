/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:38:46 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/31 12:59:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	pickup_fork(t_philo *philosopher)
{
	t_shared_resources	*shared_resources;
	struct timeval		cur_time;

	shared_resources = philosopher->shared_resources;
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	philosopher->left_fork->state = HOLD;
	philosopher->right_fork->state = HOLD;
	gettimeofday(&cur_time, NULL);
	print_message(get_timestamp(cur_time, &shared_resources->start_time), \
	philosopher->number, "has taken a fork", &shared_resources->printf_mutex);
}

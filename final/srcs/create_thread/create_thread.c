/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:51:12 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 21:56:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	detach_created_threads(pthread_t *tid_arr, uint64_t size)
{
	uint64_t	i;

	i = 0;
	while (i < size)
	{
		pthread_detach(tid_arr[i]);
		i++;
	}
}

static void	init_start_time(t_data *data, uint64_t start_ms_time)
{
	uint64_t	i;

	data->shared_data.start_ms_time = start_ms_time;
	i = 0;
	while (i < data->rule.number_of_philosophers)
	{
		data->philo_arr[i].dining_info.last_dining_time = start_ms_time;
		i++;
	}
}

void	create_thread(t_state *state, t_data *data)
{
	t_timeval	start_time;
	uint64_t	i;

	i = 0;
	pthread_mutex_lock(&data->shared_data.start_mutex);
	while (i < data->rule.number_of_philosophers)
	{
		if (pthread_create(&data->tid_arr[i], NULL, \
										dining_routine, &data->philo_arr[i]))
		{
			detach_created_threads(data->tid_arr, i);
			pthread_mutex_unlock(&data->shared_data.start_mutex);
			*state = ERROR;
			return ;
		}
		i++;
	}
	gettimeofday(&start_time, NULL);
	init_start_time(data, convert_to_ms_time(start_time));
	pthread_mutex_unlock(&data->shared_data.start_mutex);
	*state = MONITORING;
}

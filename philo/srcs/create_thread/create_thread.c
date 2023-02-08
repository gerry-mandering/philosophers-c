/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:33:50 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/07 13:40:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	init_start_time(t_data *data)
{
	uint64_t	i;

	data->start_time = get_current_time();
	i = 0;
	while (i < data->rule.number_of_philosophers)
	{
		data->philo_arr[i].dining_time.value = data->start_time;
		i++;
	}
}

static void	detach_threads(pthread_t *tid_arr, uint64_t size)
{
	uint64_t	i;

	i = 0;
	while (i < size)
	{
		pthread_detach(tid_arr[i]);
		i++;
	}
}

void	create_thread(t_state *state, t_data *data)
{
	uint64_t	i;

	i = 0;
	pthread_mutex_lock(&data->start_mutex);
	while (i < data->rule.number_of_philosophers)
	{
		if (pthread_create(&data->tid_arr[i], \
							NULL, dining_routine, &data->philo_arr[i]))
		{
			detach_threads(data->tid_arr, i);
			pthread_mutex_unlock(&data->start_mutex);
			*state = ERROR;
			return ;
		}
		i++;
	}
	init_start_time(data);
	pthread_mutex_unlock(&data->start_mutex);
	*state = MONITORING;
}

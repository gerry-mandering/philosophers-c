/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:04:51 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/20 15:32:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	monitoring(t_state *state, t_rule *rule, \
			t_shared_resources *shared_resources, t_philosopher *philosopher_arr)
{
	pthread_mutex_lock(&shared_resources->start_flag.mutex);
	shared_resources->start_flag.flag = ON;
	pthread_mutex_unlock(&shared_resources->start_flag.mutex);
	while (1)
	{
		pthread_mutex_lock(&shared_resources->dead_flag.mutex);
		if (shared_resources->dead_flag.flag == ON)
		{
			pthread_mutex_unlock(&shared_resources->dead_flag.mutex);
			break ;
		}
		pthread_mutex_unlock(&shared_resources->dead_flag.mutex);
		if (rule->number_of_meals_flag == ON)
		{
			pthread_mutex_lock(&shared_resources->finish_dinner_count.mutex);
			if (shared_resources->finish_dinner_count.finish_dinner_count == rule->number_of_meals)
			{
				pthread_mutex_unlock(&shared_resources->finish_dinner_count.mutex);
				break ;
			}
			pthread_mutex_unlock(&shared_resources->finish_dinner_count.mutex);
		}
	}
	*state = JOIN_THREADS;
}

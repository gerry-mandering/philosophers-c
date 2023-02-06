/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:26:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:23:53 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	distribute_fork(t_philo *philo_arr, t_data *data, uint64_t i)
{
	philo_arr[i].left_fork = &data->fork_arr[i];
	if (i == 0)
		philo_arr[i].right_fork = \
					&data->fork_arr[data->rule.number_of_philosophers - 1];
	else
		philo_arr[i].right_fork = &data->fork_arr[i - 1];
}

t_philo	*init_philo_arr(t_state *state, t_data *data)
{
	t_philo		*philo_arr;
	uint64_t	i;

	philo_arr = ft_malloc(state, \
						sizeof(t_philo) * data->rule.number_of_philosophers);
	i = 0;
	while (*state != ERROR && i < data->rule.number_of_philosophers)
	{
		philo_arr[i].number = i + 1;
		philo_arr[i].rule = data->rule;
		philo_arr[i].start_mutex = &data->start_mutex;
		philo_arr[i].start_time = &data->start_time;
		philo_arr[i].dining_count.value = 0;
		philo_arr[i].break_flag = &data->break_flag;
		distribute_fork(philo_arr, data, i);
		ft_pthread_mutex_init(state, &philo_arr[i].dining_time.mutex, NULL);
		ft_pthread_mutex_init(state, &philo_arr[i].dining_count.mutex, NULL);
		i++;
	}
	if (*state != ERROR)
		*state = INIT_TID_ARR;
	return (philo_arr);
}

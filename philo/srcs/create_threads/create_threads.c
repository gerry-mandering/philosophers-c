/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:10:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 19:40:33 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	create_threads(t_state *state, t_spec *spec, \
		t_shared_resources *shared_resources, t_philosopher *philosopher_arr)
{
	uint64_t	i;
	int			ret;

	i = 0;
	while (i < spec->number_of_philosophers)
	{
		ret = pthread_create(&philosopher_arr[i].thread, NULL, \
										dinning_routine, philosopher_arr[i]);
		if (ret != 0)
		{
			*state = ERROR;
			return ;
		}
		i++;
	}
	*state = MONITORING;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:54:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/21 17:32:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_philosopher_arr(t_state *state, t_rule *rule, \
		t_shared_resources *shared_resources, t_philosopher **philosopher_arr)
{
	uint64_t	i;

	(*philosopher_arr) = (t_philosopher *)malloc(sizeof(t_philosopher) * \
												rule->number_of_philosophers);
	if ((*philosopher_arr) == NULL)
	{
		*state = ERROR;
		return ;
	}
	i = 0;
	while (i < rule->number_of_philosophers)
	{
		(*philosopher_arr)[i].number = i + 1;
		(*philosopher_arr)[i].rule = *rule;
		(*philosopher_arr)[i].finish_dinner_count = &shared_resources->finish_dinner_count;
		(*philosopher_arr)[i].start_flag = &shared_resources->start_flag;
		(*philosopher_arr)[i].start_time = &shared_resources->start_time;
		(*philosopher_arr)[i].dead_flag = &shared_resources->dead_flag;
		(*philosopher_arr)[i].left_fork = &shared_resources->fork_arr[i];
		if (i != rule->number_of_philosophers - 1)
			(*philosopher_arr)[i].right_fork = \
											&shared_resources->fork_arr[i + 1];
		else
			(*philosopher_arr)[i].right_fork = &shared_resources->fork_arr[0];
		i++;
	}
	*state = CREATE_THREADS;
}

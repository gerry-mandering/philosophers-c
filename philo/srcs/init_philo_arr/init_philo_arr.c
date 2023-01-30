/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:11:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 10:09:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	assign_value(t_philo *philo_arr, \
							t_shared_resources *shared_resources, t_rule *rule)
{
	uint64_t	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		philo_arr[i].rule = *rule;
		philo_arr[i].shared_resources = shared_resources;
		philo_arr[i].number = i + 1;
		philo_arr[i].left_fork = &shared_resources->fork_arr[i];
		if (i != rule->number_of_philosophers - 1)
			philo_arr[i].right_fork = &shared_resources->fork_arr[i + 1];
		else
			philo_arr[i].right_fork = &shared_resources->fork_arr[0];
		i++;
	}
}

void	init_philo_arr(t_state *state, t_rule *rule, \
					t_shared_resources *shared_resources, t_philo **philo_arr)
{
	*philo_arr = (t_philo *)malloc(sizeof(t_philo) * \
												rule->number_of_philosophers);
	if (*philo_arr == NULL)
	{
		*state = ERROR;
		return ;
	}
	assign_value(*philo_arr, shared_resources, rule);
	*state = CREATE_THREADS;
}

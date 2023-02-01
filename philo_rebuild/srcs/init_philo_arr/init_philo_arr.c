/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 16:04:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// function declaration
static void	assign_philo_arr_variables(t_rule *rule, \
						t_shared_resource *shared_resource, t_philo *philo_arr);

void	init_philo_arr(enum e_state *state, \
		t_rule *rule, t_shared_resource *shared_resource, t_philo **philo_arr)
{
	*philo_arr = (t_philo *)ft_malloc(state, rule->number_of_philosophers);
	if (*state == ERROR)
		return ;
	assign_philo_arr_variables(rule, shared_resource, *philo_arr);
	*state = CREATE_THREAD;
}

static void	assign_philo_arr_variables(t_rule *rule, \
						t_shared_resource *shared_resource, t_philo *philo_arr)
{
	uint64_t	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		philo_arr[i].number = i + 1;
		philo_arr[i].rule = *rule;
		philo_arr[i].shared_resource = shared_resource;
		philo_arr[i].dining_count = 0;
		philo_arr[i].left_fork = &shared_resource->fork_arr[i];
		if (i == 0)
			philo_arr[i].right_fork = \
				&shared_resource->fork_arr[rule->number_of_philosophers - 1];
		else
			philo_arr[i].right_fork = &shared_resource->fork_arr[i - 1];
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared_resource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:22:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 19:20:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// function declaration
static void	init_fork_arr(enum e_state *state, \
							t_rule *rule, t_shared_resource *shared_resource);

void	init_shared_resource(enum e_state *state, \
							t_rule *rule, t_shared_resource *shared_resource)
{
	memset(shared_resource, 0, sizeof(t_shared_resource));
	init_fork_arr(state, rule, shared_resource);
	ft_pthread_mutex_init(state, &shared_resource->start_mutex, NULL);
	ft_pthread_mutex_init(state, &shared_resource->dead_flag.mutex, NULL);
	ft_pthread_mutex_init(state, \
			&shared_resource->finished_dining_count.mutex, NULL);
	ft_pthread_mutex_init(state, &shared_resource->msg_print_mutex, NULL);
	if (*state == ERROR)
		return ;
	*state = INIT_PHILO_ARR;
}

static void	init_fork_arr(enum e_state *state, \
							t_rule *rule, t_shared_resource *shared_resource)
{
	t_fork		*fork_arr;
	uint64_t	i;

	fork_arr = (t_fork *)ft_malloc(state, \
								sizeof(t_fork) * rule->number_of_philosophers);
	if (*state == ERROR)
		return ;
	i = 0;
	while (i < rule->number_of_philosophers)
	{
		fork_arr[i].state = RELEASE;
		ft_pthread_mutex_init(state, &fork_arr[i].mutex, NULL);
		if (*state == ERROR)
			return ;
		i++;
	}
	shared_resource->fork_arr = fork_arr;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared_resources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:25:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 13:33:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static t_fork	*get_fork_arr(t_state *state, t_rule *rule)
{
	t_fork		*fork_arr;
	uint64_t	i;

	fork_arr = (t_fork *)malloc(sizeof(t_fork) * rule->number_of_philosophers);
	if (fork_arr == NULL)
	{
		*state = ERROR;
		return (NULL);
	}
	i = 0;
	while (i < rule->number_of_philosophers)
	{
		fork_arr[i].state = RELEASE;
		pthread_mutex_init(&fork_arr[i].mutex, NULL);
		i++;
	}
	return (fork_arr);
}

void	init_shared_resources(t_state *state, t_rule *rule, \
										t_shared_resources *shared_resources)
{
	memset(shared_resources, 0, sizeof(t_shared_resources));
	shared_resources->fork_arr = get_fork_arr(state, rule);
	if (*state == ERROR)
		return ;
	pthread_mutex_init(&shared_resources->start_flag.mutex, NULL);
	pthread_mutex_init(&shared_resources->start_time.mutex, NULL);
	pthread_mutex_init(&shared_resources->dead_flag.mutex, NULL);
	pthread_mutex_init(&shared_resources->finished_dining_count.mutex, NULL);
	pthread_mutex_init(&shared_resources->printf_mutex, NULL);
	*state = INIT_PHILO_ARR;
}

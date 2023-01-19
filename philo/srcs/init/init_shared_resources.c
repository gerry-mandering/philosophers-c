/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared_resources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:39:59 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 18:12:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static t_fork	*init_fork_arr(t_state *state, t_spec *spec)
{
	t_fork		*fork_arr;
	uint64_t	i;
	int			ret;

	fork_arr = (t_fork *)malloc(sizeof(t_fork) * spec->number_of_philosophers);
	if (fork_arr == NULL)
	{
		*state = ERROR;
		return (NULL);
	}
	i = 0;
	while (i < spec->number_of_philosophers)
	{
		fork_arr[i].fork_state = RELEASE;
		ret = pthread_mutex_init(&fork_arr[i].fork_mutex, NULL);
		if (ret != 0)
		{
			free(fork_arr);
			*state = ERROR;
			return (NULL);
		}
		i++;
	}
	return (fork_arr);
}

void	init_shared_resources(t_state *state, \
							t_spec *spec, t_shared_resources *shared_resources)
{
	shared_resources->fork_arr = init_fork_arr(state, spec);
	shared_resources->start_flag = OFF;
	*state = INIT_PHILOSOPHER_ARR;
}

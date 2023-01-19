/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:54:57 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 18:11:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_philosopher_arr(t_state *state, t_spec *spec, \
		t_shared_resources *shared_resources, t_philosopher **philosopher_arr)
{
	uint64_t	i;

	(*philosopher_arr) = (t_philosopher *)malloc(sizeof(t_philosopher) * \
												spec->number_of_philosophers);
	if ((*philosopher_arr) == NULL)
	{
		*state = ERROR;
		return ;
	}
	i = 0;
	while (i < spec->number_of_philosophers)
	{
		(*philosopher_arr)[i].number = i + 1;
		(*philosopher_arr)[i].left_fork = &shared_resources->fork_arr[i];
		if (i != spec->number_of_philosophers - 1)
			(*philosopher_arr)[i].right_fork = \
											&shared_resources->fork_arr[i + 1];
		else
			(*philosopher_arr)[i].right_fork = &shared_resources->fork_arr[0];
		i++;
	}
	*state = CREATE_THREADS;
}
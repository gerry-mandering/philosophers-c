/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:26:18 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 09:26:26 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

t_fork	*init_fork_arr(t_state *state, t_rule rule)
{
	t_fork		*fork_arr;
	uint64_t	i;

	fork_arr = ft_malloc(state, sizeof(t_fork) * rule.number_of_philosophers);
	i = 0;
	while (*state != ERROR && i < rule.number_of_philosophers)
	{
		fork_arr[i].state = RELEASE;
		ft_pthread_mutex_init(state, &fork_arr[i].mutex, NULL);
		i++;
	}
	if (*state != ERROR)
		*state = INIT_PHILO_ARR;
	return (fork_arr);
}

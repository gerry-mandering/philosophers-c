/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:54:46 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 09:56:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	join_threads(t_state *state, t_rule *rule, t_philo *philo_arr)
{
	uint64_t	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		pthread_join(philo_arr[i].thread, NULL);
		i++;
	}
	*state = CLEAR;
}

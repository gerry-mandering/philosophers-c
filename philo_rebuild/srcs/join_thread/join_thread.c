/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:59:34 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 16:03:18 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	join_thread(enum e_state *state, t_rule *rule, pthread_t *tid_arr)
{
	uint64_t	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		pthread_join(tid_arr[i], NULL);
		i++;
	}
	*state = FINISH;
}

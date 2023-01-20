/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:39:22 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/20 14:44:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	join_thread(t_state *state, t_rule *rule, \
												t_philosopher *philosopher_arr)
{
	uint64_t	i;
	int			ret;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		ret = pthread_join(philosopher_arr[i].thread, NULL);
		if (ret != 0)
		{
			*state = ERROR;
			return ;
		}
		i++;
	}
}

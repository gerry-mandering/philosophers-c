/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:38:21 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 19:17:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	join_thread(t_state *state, t_data *data)
{
	uint64_t	i;

	i = 0;
	while (i < data->rule.number_of_philosophers)
	{
		pthread_join(data->tid_arr[i], NULL);
		i++;
	}
	*state = FINISH;
}

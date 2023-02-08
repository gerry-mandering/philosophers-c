/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tid_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:27:07 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/07 12:47:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

pthread_t	*init_tid_arr(t_state *state, t_data *data)
{
	pthread_t	*tid_arr;

	tid_arr = ft_malloc(state, \
						sizeof(pthread_t) * data->rule.number_of_philosophers);
	if (*state != ERROR)
		*state = CREATE_THREAD;
	return (tid_arr);
}

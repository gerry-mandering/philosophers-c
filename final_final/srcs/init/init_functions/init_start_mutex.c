/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:17:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

pthread_mutex_t	init_start_mutex(t_state *state)
{
	pthread_mutex_t	start_mutex;

	ft_pthread_mutex_init(state, &start_mutex, NULL);
	if (*state != ERROR)
		*state = INIT_FORK_ARR;
	return (start_mutex);
}

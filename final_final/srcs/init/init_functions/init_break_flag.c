/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_break_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:26:01 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:19:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

t_flag	init_break_flag(t_state *state)
{
	t_flag	break_flag;

	break_flag.state = false;
	ft_pthread_mutex_init(state, &break_flag.mutex, NULL);
	if (*state != ERROR)
		*state = INIT_START_MUTEX;
	return (break_flag);
}

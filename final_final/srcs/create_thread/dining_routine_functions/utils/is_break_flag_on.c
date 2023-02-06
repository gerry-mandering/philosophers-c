/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_break_flag_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:36:31 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:37:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/philo.h"

bool	is_break_flag_on(t_flag *break_flag)
{
	pthread_mutex_lock(&break_flag->mutex);
	if (break_flag->state == true)
	{
		pthread_mutex_unlock(&break_flag->mutex);
		return (true);
	}
	else
		return (false);
}

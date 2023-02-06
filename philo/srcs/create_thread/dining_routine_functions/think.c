/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:00 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:46:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	think(t_dining_state *dining_state, t_philo *philo)
{
	if (is_break_flag_on(philo->break_flag))
	{
		*dining_state = FINISH_DINING;
		return ;
	}
	else
	{
		print_msg(philo, get_current_time(), "is thinking");
		pthread_mutex_unlock(&philo->break_flag->mutex);
		*dining_state = PICKUP_LEFT_FORK;
	}
}

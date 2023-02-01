/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_fork_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:17:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 20:19:10 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	return_fork_back(enum e_dining_state dining_state, t_philo *philo)
{
	if (dining_state == PICKUP_LEFT_FORK)
		putdown_left_fork(philo);
	else if (dining_state == PICKUP_RIGHT_FORK || dining_state == EAT)
	{
		putdown_left_fork(philo);
		putdown_right_fork(philo);
	}
	else if (dining_state == PUTDOWN_LEFT_FORK)
		putdown_right_fork(philo);
}

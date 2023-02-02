/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_holding_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:07:02 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 13:41:56 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	is_holding_fork(enum e_dining_state dining_state)
{
	if (dining_state >= PICKUP_LEFT_FORK && dining_state <= PUTDOWN_LEFT_FORK)
		return (1);
	else
		return (0);
}

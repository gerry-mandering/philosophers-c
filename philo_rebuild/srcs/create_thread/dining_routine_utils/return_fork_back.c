/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_fork_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:17:05 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 13:44:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	return_fork_back(enum e_dining_state dining_state, t_philo *philo)
{
	if (dining_state == PICKUP_LEFT_FORK || dining_state == PICKUP_RIGHT_FORK)
	{
		philo->left_fork->state = RELEASE;
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
	if (dining_state == EAT || dining_state == PUTDOWN_LEFT_FORK)
	{
		philo->right_fork->state = RELEASE;
		pthread_mutex_unlock(&philo->right_fork->mutex);
	}
}

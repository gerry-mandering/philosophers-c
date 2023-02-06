/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup_left_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:32:16 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 15:48:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

static void	return_fork(t_philo *philo)
{
	philo->left_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->left_fork->mutex);
}

void	pickup_left_fork(t_dining_state *dining_state, t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->state = HOLD;
	if (is_break_flag_on(philo->break_flag))
	{
		return_fork(philo);
		*dining_state = FINISH_DINING;
		return ;
	}
	else
	{
		print_msg(philo, get_current_time(), "has taken a fork");
		pthread_mutex_unlock(&philo->break_flag->mutex);
		if (philo->rule.number_of_philosophers == 1)
			*dining_state = FINISH_DINING;
		else
			*dining_state = PICKUP_RIGHT_FORK;
	}
}

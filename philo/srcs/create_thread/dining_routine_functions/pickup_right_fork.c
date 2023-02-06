/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup_right_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:32:41 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 15:49:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

static void	return_fork(t_philo *philo)
{
	philo->left_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	pickup_right_fork(t_dining_state *dining_state, t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->state = HOLD;
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
		*dining_state = EAT;
	}
}

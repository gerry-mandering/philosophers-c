/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdown_left_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:47:52 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 22:00:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	putdown_left_fork(t_dining_state *dining_state, t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->shared_data->break_flag.mutex);
	if (philo->shared_data->break_flag.state == true)
	{
		pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
		*dining_state = BREAK;
		return ;
	}
	philo->left_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
	*dining_state = PUTDOWN_RIGHT_FORK;
}

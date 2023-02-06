/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdown_right_fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:49:13 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/05 19:30:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	putdown_right_fork(t_dining_state *dining_state, t_philo *philo)
{
	//printf("%llu %s\n", philo->number, __func__);
	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->shared_data->break_flag.mutex);
	if (philo->shared_data->break_flag.state == true)
	{
		pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
		*dining_state = BREAK;
		return ;
	}
	pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
	*dining_state = GO_SLEEP;
}

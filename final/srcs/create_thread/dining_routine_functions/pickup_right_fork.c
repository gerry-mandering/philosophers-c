/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup_right_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:31:28 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/05 22:28:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

static void	return_fork_back(t_philo *philo)
{
	philo->left_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	pickup_right_fork(t_dining_state *dining_state, t_philo *philo)
{
	t_timeval	current_time;

	pthread_mutex_lock(&philo->right_fork->mutex);
	//printf("%s %llu %p\n", __func__, philo->number, &philo->right_fork->mutex);
	philo->right_fork->state = HOLD;
	pthread_mutex_lock(&philo->shared_data->break_flag.mutex);
	if (philo->shared_data->break_flag.state == true)
	{
		pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
		return_fork_back(philo);
		*dining_state = BREAK;
		return ;
	}
	pthread_mutex_unlock(&philo->shared_data->break_flag.mutex);
	pthread_mutex_lock(&philo->shared_data->print_mutex);
	gettimeofday(&current_time, NULL);
	print_msg(philo, convert_to_ms_time(current_time), "has taken a fork");
	pthread_mutex_unlock(&philo->shared_data->print_mutex);
	*dining_state = EAT;
}

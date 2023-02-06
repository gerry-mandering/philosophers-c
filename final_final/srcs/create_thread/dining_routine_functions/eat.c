/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:35:41 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 15:50:00 by minseok2         ###   ########.fr       */
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

static void	renew_dining_time(t_time *dining_time, uint64_t current_time)
{
	pthread_mutex_lock(&dining_time->mutex);
	dining_time->value = current_time;
	pthread_mutex_unlock(&dining_time->mutex);
}

static void	renew_dining_count(t_count *dining_count)
{
	pthread_mutex_lock(&dining_count->mutex);
	dining_count->value++;
	pthread_mutex_unlock(&dining_count->mutex);
}

void	eat(t_dining_state *dining_state, t_philo *philo)
{
	uint64_t	current_time;

	if (is_break_flag_on(philo->break_flag))
	{
		return_fork(philo);
		*dining_state = FINISH_DINING;
		return ;
	}
	else
	{
		current_time = get_current_time();
		print_msg(philo, current_time, "is eating");
		pthread_mutex_unlock(&philo->break_flag->mutex);
		renew_dining_time(&philo->dining_time, current_time);
		ft_usleep(current_time, philo->rule.time_to_eat);
		if (philo->rule.required_meal_flag == true)
			renew_dining_count(&philo->dining_count);
		*dining_state = PUTDOWN_LEFT_FORK;
	}
}

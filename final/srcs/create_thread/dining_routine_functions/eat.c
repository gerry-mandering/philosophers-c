/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:31:55 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/05 22:27:38 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <unistd.h>

static void	return_fork_back(t_philo *philo)
{
	philo->left_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

static void	update_dining_info(t_philo *philo, t_timeval current_time)
{
	pthread_mutex_lock(&philo->dining_info.mutex);
	philo->dining_info.last_dining_time = convert_to_ms_time(current_time);
	if (philo->rule.required_meal_flag == true)
		philo->dining_info.dining_count++;
	pthread_mutex_unlock(&philo->dining_info.mutex);
}

void	eat(t_dining_state *dining_state, t_philo *philo)
{
	t_timeval	current_time;

	//printf("%llu %s\n", philo->number, __func__);
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
	print_msg(philo, convert_to_ms_time(current_time), "is eating");
	pthread_mutex_unlock(&philo->shared_data->print_mutex);
	update_dining_info(philo, current_time);
	ft_usleep(convert_to_ms_time(current_time), philo->rule.time_to_eat);
	gettimeofday(&current_time, NULL);
	*dining_state = PUTDOWN_LEFT_FORK;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_dead_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:07:02 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 18:50:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	raise_dead_flag(t_philo *philo, t_timeval current_time)
{
	pthread_mutex_lock(&philo->shared_resource->dead_flag.mutex);
	philo->shared_resource->dead_flag.state = ON;
	print_msg(philo, current_time, "died");
	pthread_mutex_unlock(&philo->shared_resource->dead_flag.mutex);
}

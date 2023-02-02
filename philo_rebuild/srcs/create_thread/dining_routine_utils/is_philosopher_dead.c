/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philosopher_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:22:47 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 16:43:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	is_philosopher_dead(t_philo *philo, t_timeval current_time)
{
	uint64_t	start_ms_time;
	uint64_t	current_ms_time;
	uint64_t	time_diff;

	start_ms_time = convert_to_ms(philo->last_dining_time);
	current_ms_time = convert_to_ms(current_time);
	time_diff = current_ms_time - start_ms_time;
	if (time_diff > philo->rule.time_to_die)
		return (1);
	else
		return (0);
}

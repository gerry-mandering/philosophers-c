/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:55:21 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/05 13:37:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_msg(t_philo *philo, uint64_t current_ms_time, const char *msg)
{
	uint64_t	time_diff;

	time_diff = current_ms_time - philo->shared_data->start_ms_time;
	printf("%llu %llu %s\n", time_diff, philo->number, msg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:28:53 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 16:38:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	print_msg(t_philo *philo, t_timeval current_time, const char *msg)
{
	uint64_t	start_ms_time;
	uint64_t	current_ms_time;
	uint64_t	time_diff;

	start_ms_time = convert_to_ms(philo->shared_resource->start_time);
	current_ms_time = convert_to_ms(current_time);
	time_diff = current_ms_time - start_ms_time;
	printf("%llu %llu %s\n", time_diff, philo->number, msg);
}

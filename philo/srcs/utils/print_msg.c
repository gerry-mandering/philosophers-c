/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:55:21 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 11:11:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_msg(t_philo *philo, uint64_t current_time, const char *msg)
{
	uint64_t	time_diff;

	time_diff = current_time - *philo->start_time;
	printf("%llu %llu %s\n", time_diff, philo->number, msg);
}

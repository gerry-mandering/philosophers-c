/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:58:09 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 13:00:50 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

uint64_t	convert_to_ms(t_timeval time)
{
	uint64_t	millisecond;

	millisecond = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (millisecond);
}

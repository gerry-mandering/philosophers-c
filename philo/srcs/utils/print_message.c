/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:41:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 13:44:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_message(uint64_t timestamp, uint64_t number, \
								const char *msg, pthread_mutex_t *printf_mutex)
{
	pthread_mutex_lock(printf_mutex);
	printf("%lld %lld %s\n", timestamp, number, msg);
	pthread_mutex_unlock(printf_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_mutex_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:24:04 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 17:05:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_pthread_mutex_init(enum e_state *state, \
						pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
{
	int	ret;

	if (*state == ERROR)
		return (1);
	ret = pthread_mutex_init(mutex, attr);
	if (ret != 0)
	{
		*state = ERROR;
		return (ret);
	}
	return (ret);
}

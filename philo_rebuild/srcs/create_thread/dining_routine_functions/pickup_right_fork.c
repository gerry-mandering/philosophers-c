/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup_right_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:47:02 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 18:50:29 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	pickup_right_fork(t_philo *philo)
{
	int					ret;

	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->state = HOLD;
	ret = print_msg(philo, "has taken a fork");
	return (ret);
}

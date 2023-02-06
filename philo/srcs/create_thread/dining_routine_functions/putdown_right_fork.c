/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdown_right_fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:35:17 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:45:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void	putdown_right_fork(t_dining_state *dining_state, t_philo *philo)
{
	philo->right_fork->state = RELEASE;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	*dining_state = GO_SLEEP;
}

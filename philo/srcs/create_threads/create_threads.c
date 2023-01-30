/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:21:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 13:39:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	create_threads(t_state *state, t_rule *rule, t_philo *philo_arr)
{
	uint64_t	i;

	i = 0;
	while (i < rule->number_of_philosophers)
	{
		pthread_create(&philo_arr[i].thread, NULL, dining_routine, \
																&philo_arr[i]);
		i++;
	}
	*state = MONITORING;
}

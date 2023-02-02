/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:45:24 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 16:37:58 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	enum e_state		state;
	t_rule				rule;
	t_shared_resource	shared_resource;
	t_philo				*philo_arr;
	pthread_t			*tid_arr;

	state = INIT_RULE;
	while (state != FINISH)
	{
		if (state == INIT_RULE)
			init_rule(&state, &rule, argc, argv);
		else if (state == INIT_SHARED_RESOURCE)
			init_shared_resource(&state, &rule, &shared_resource);
		else if (state == INIT_PHILO_ARR)
			init_philo_arr(&state, &rule, &shared_resource, &philo_arr);
		else if (state == CREATE_THREAD)
		{
			pthread_mutex_lock(&shared_resource.start_mutex);
			create_thread(&state, &rule, philo_arr, &tid_arr);
		}
		else if (state == MONITORING)
			monitoring(&state, &rule, &shared_resource);
		else if (state == JOIN_THREAD)
			join_thread(&state, &rule, tid_arr);
		else if (state == ERROR)
			error(&state);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:38:33 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 15:03:05 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	fsm(int argc, char **argv)
{
	t_state				state;
	t_rule				rule;
	t_shared_resources	shared_resources;
	t_philo				*philo_arr;

	state = INIT_RULE;
	while (state != FINISH)
	{
		if (state == INIT_RULE)
			init_rule(&state, &rule, argc, argv);
		else if (state == INIT_SHARED_RESOURCES)
			init_shared_resources(&state, &rule, &shared_resources);
		else if (state == INIT_PHILO_ARR)
			init_philo_arr(&state, &rule, &shared_resources, &philo_arr);
		else if (state == CREATE_THREADS)
			create_threads(&state, &rule, philo_arr);
		else if (state == MONITORING)
			monitoring(&state, &rule, &shared_resources);
		else if (state == JOIN_THREADS)
			join_threads(&state, &rule, philo_arr);
		else if (state == CLEAR)
			clear(&state, &rule, &shared_resources, philo_arr);
		else if (state == ERROR)
			error(&state);
	}
}

int	main(int argc, char **argv)
{
	fsm(argc, argv);
	return (0);
}

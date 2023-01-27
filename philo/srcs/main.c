/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:38:33 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/27 17:27:24 by minseok2         ###   ########.fr       */
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
			init_shared_resources(&state, &shared_resources, &rule);
		else if (state == INIT_PHILO_ARR)
			init_philo_arr(&state, &philo_arr, &shared_resources, &rule);
		else if (state == CREATE_THREADS)
			create_threads();
		else if (state == MONITORING)
			monitoring();
		else if (state == JOIN_THREADS)
			join_threads();
		else if (state == CLEAR)
			clear();
		else if (state == ERROR)
			error(&state);
	}
}

int	main(int argc, char **argv)
{
	fsm(argc, argv);
	return (0);
}

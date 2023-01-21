/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:09:44 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/21 15:06:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error(t_state *state)
{
	printf("Error occurred\n");
	*state = FINISH;
}

int	main(int argc, char **argv)
{
	t_state				state;
	t_rule				rule;
	t_shared_resources	shared_resources;
	t_philosopher		*philosopher_arr;

	state = INIT_RULE;
	while (state != FINISH)
	{
		if (state == INIT_RULE)
			init_rule(&state, &rule, argc, argv);
		else if (state == INIT_SHARED_RESOURCES)
			init_shared_resources(&state, &rule, &shared_resources);
		else if (state == INIT_PHILOSOPHER_ARR)
			init_philosopher_arr(&state, &rule, &shared_resources, \
															&philosopher_arr);
		else if (state == CREATE_THREADS)
			create_threads(&state, &rule, &shared_resources, \
															philosopher_arr);
		else if (state == MONITORING)
			monitoring(&state, &rule, &shared_resources, \
															philosopher_arr);
		else if (state == JOIN_THREADS)
			join_thread(&state, &rule, philosopher_arr);
		else if (state == ERROR)
			error(&state);
	}
	return (0);
}

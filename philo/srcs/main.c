/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:09:44 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 19:37:14 by minseok2         ###   ########.fr       */
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
	t_spec				spec;
	t_shared_resources	shared_resources;
	t_philosopher		*philosopher_arr;

	state = INIT_SPEC;
	while (state != FINISH)
	{
		if (state == INIT_SPEC)
			init_spec(&state, &spec, argc, argv);
		else if (state == INIT_SHARED_RESOURCES)
			init_shared_resources(&state, &spec, &shared_resources);
		else if (state == INIT_PHILOSOPHER_ARR)
			init_philosopher_arr(&state, &spec, &shared_resources, \
															&philosopher_arr);
		else if (state == CREATE_THREADS)
			create_threads(&state, &spec, &shared_resources, \
															philosopher_arr);
		else if (state == MONITORING)
			monitoring();
		else if (state == JOIN_THREADS)
			join_thread();
		else if (state == ERROR)
			error(&state);
	}
	return (0);
}

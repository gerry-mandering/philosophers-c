/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:17:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 18:11:57 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_spec(t_state *state, t_spec *spec, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		*state = ERROR;
	init_number_of_philosophers(state, &spec->number_of_philosophers, argv[1]);
	init_time_to_die(state, &spec->time_to_die, argv[2]);
	init_time_to_eat(state, &spec->time_to_eat, argv[3]);
	init_time_to_sleep(state, &spec->time_to_sleep, argv[4]);
	if (argc == 6)
		init_number_of_meals(state, &spec->number_of_meals, argv[5]);
	*state = INIT_SHARED_RESOURCES;
}

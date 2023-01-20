/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:17:20 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/20 14:41:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_rule(t_state *state, t_rule *rule, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		*state = ERROR;
	init_number_of_philosophers(state, &rule->number_of_philosophers, argv[1]);
	init_time_to_die(state, &rule->time_to_die, argv[2]);
	init_time_to_eat(state, &rule->time_to_eat, argv[3]);
	init_time_to_sleep(state, &rule->time_to_sleep, argv[4]);
	if (argc == 6)
	{
		rule->number_of_meals_flag = ON;
		init_number_of_meals(state, &rule->number_of_meals, argv[5]);
	}
	else
		rule->number_of_meals_flag = OFF;
	*state = INIT_SHARED_RESOURCES;
}

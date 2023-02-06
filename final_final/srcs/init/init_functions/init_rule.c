/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:25:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 13:09:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

t_rule	init_rule(t_state *state, int argc, char **argv)
{
	t_rule	rule;

	if (argc != 5 && argc != 6)
		*state = ERROR;
	rule.number_of_philosophers = ascii_to_ull(state, argv[1]);
	rule.time_to_die = ascii_to_ull(state, argv[2]);
	rule.time_to_eat = ascii_to_ull(state, argv[3]);
	rule.time_to_sleep = ascii_to_ull(state, argv[4]);
	if (argc == 6)
	{
		rule.required_meal_flag = true;
		rule.required_meal_count = ascii_to_ull(state, argv[5]);
	}
	else
		rule.required_meal_flag = false;
	if (*state != ERROR)
		*state = INIT_BREAK_FLAG;
	return (rule);
}

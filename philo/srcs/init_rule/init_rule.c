/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:10:58 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 16:57:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_basic_rule(t_state *state, t_rule *rule, char **argv)
{
	rule->number_of_philosophers = ascii_to_ull(state, argv[1]);
	rule->time_to_die = ascii_to_ull(state, argv[2]);
	rule->time_to_eat = ascii_to_ull(state, argv[3]);
	rule->time_to_sleep = ascii_to_ull(state, argv[4]);
}

void	init_additional_rule(t_state *state, t_rule *rule, char **argv)
{
	rule->required_number_of_meals = ascii_to_ull(state, argv[5]);
}

void	init_rule(t_state *state, t_rule *rule, int argc, char **argv)
{
	if (argc == 5)
	{
		rule->required_number_of_meals_flag = OFF;
		init_basic_rule(state, rule, argv);
	}
	else if (argc == 6)
	{
		rule->required_number_of_meals_flag = ON;
		init_basic_rule(state, rule, argv);
		init_additional_rule(state, rule, argv);
	}
	else
	{
		*state = ERROR;
		return ;
	}
	if (*state != ERROR)
		*state = INIT_SHARED_RESOURCES;
}

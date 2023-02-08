/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:25:39 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/07 13:22:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

static void	init_basic_rule(t_state *state, t_rule *rule, char **argv)
{
	rule->number_of_philosophers = ascii_to_ull(state, argv[1]);
	rule->time_to_die = ascii_to_ull(state, argv[2]);
	rule->time_to_eat = ascii_to_ull(state, argv[3]);
	rule->time_to_sleep = ascii_to_ull(state, argv[4]);
	if (rule->number_of_philosophers == 0 || rule->time_to_die == 0 || \
			rule->time_to_eat == 0 || rule->time_to_sleep == 0)
		*state = ERROR;
}

static void	init_additional_rule(t_state *state, t_rule *rule, char **argv)
{
	rule->required_meal_flag = true;
	rule->required_meal_count = ascii_to_ull(state, argv[5]);
	if (*state != ERROR && rule->required_meal_count == 0)
		*state = FINISH;
}

t_rule	init_rule(t_state *state, int argc, char **argv)
{
	t_rule	rule;

	memset(&rule, 0, sizeof(t_rule));
	if (argc != 5 && argc != 6)
	{
		*state = ERROR;
		return (rule);
	}
	init_basic_rule(state, &rule, argv);
	if (*state == ERROR)
		return (rule);
	if (argc == 6)
	{
		init_additional_rule(state, &rule, argv);
		if (*state == ERROR || *state == FINISH)
			return (rule);
	}
	*state = INIT_BREAK_FLAG;
	return (rule);
}

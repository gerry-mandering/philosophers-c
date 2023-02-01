/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:10:35 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 13:20:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	print_test(t_rule *rule);

void	init_rule(enum e_state *state, t_rule *rule, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		*state = ERROR;
		return ;
	}
	rule->number_of_philosophers = ascii_to_ull(state, argv[1]);
	rule->time_to_die = ascii_to_ull(state, argv[2]);
	rule->time_to_eat = ascii_to_ull(state, argv[3]);
	rule->time_to_sleep = ascii_to_ull(state, argv[4]);
	if (argc == 6)
	{
		rule->required_number_of_meals_flag = ON;
		rule->required_number_of_meals = ascii_to_ull(state, argv[5]);
	}
	//test_code
	print_test(rule);
	if (*state == ERROR)
		return ;
	*state = INIT_SHARED_RESOURCE;
}

static void	print_test(t_rule *rule)
{
	printf("number_of_philosophers = %llu\n", rule->number_of_philosophers);
	printf("time_to_die = %llu\n", rule->time_to_die);
	printf("time_to_eat = %llu\n", rule->time_to_eat);
	printf("time_to_sleep = %llu\n", rule->time_to_sleep);
	if (rule->required_number_of_meals_flag == ON)
		printf("required_number_of_meals = %llu\n", rule->required_number_of_meals);
}

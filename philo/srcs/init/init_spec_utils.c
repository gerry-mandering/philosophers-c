/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spec_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:24:03 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 12:30:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_number_of_philosophers(t_state *state, \
									uint64_t *number_of_philosophers, char *arg)
{
	if (*state == ERROR)
		return ;
	*number_of_philosophers = ascii_to_ull(state, arg);
}

void	init_time_to_die(t_state *state, uint64_t *time_to_die, char *arg)
{
	if (*state == ERROR)
		return ;
	*time_to_die = ascii_to_ull(state, arg);
}

void	init_time_to_eat(t_state *state, uint64_t *time_to_eat, char *arg)
{
	if (*state == ERROR)
		return ;
	*time_to_eat = ascii_to_ull(state, arg);
}

void	init_time_to_sleep(t_state *state, uint64_t *time_to_sleep, char *arg)
{
	if (*state == ERROR)
		return ;
	*time_to_sleep = ascii_to_ull(state, arg);
}

void	init_number_of_meals(t_state *state, \
										uint64_t *number_of_meals, char *arg)
{
	if (*state == ERROR)
		return ;
	*number_of_meals = ascii_to_ull(state, arg);
}

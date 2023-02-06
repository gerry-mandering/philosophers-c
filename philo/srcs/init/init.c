/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:38:46 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:25 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init(t_state *state, t_data *data, int argc, char **argv)
{
	*state = INIT_RULE;
	while (true)
	{
		if (*state == INIT_RULE)
			data->rule = init_rule(state, argc, argv);
		else if (*state == INIT_BREAK_FLAG)
			data->break_flag = init_break_flag(state);
		else if (*state == INIT_START_MUTEX)
			data->start_mutex = init_start_mutex(state);
		else if (*state == INIT_FORK_ARR)
			data->fork_arr = init_fork_arr(state, data->rule);
		else if (*state == INIT_PHILO_ARR)
			data->philo_arr = init_philo_arr(state, data);
		else if (*state == INIT_TID_ARR)
			data->tid_arr = init_tid_arr(state, data);
		else if (*state == FINISH_INIT)
			break ;
		else if (*state == ERROR)
			return ;
	}
	*state = CREATE_THREAD;
}

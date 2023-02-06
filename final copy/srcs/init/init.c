/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:38:17 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/03 18:46:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init(t_state *state, t_data *data, int argc, char **argv)
{
	init_rule(state, &data->rule, argc, argv);
	init_shared_data(state, &data->shared_data);
	init_fork_arr(state, data);
	init_philo_arr(state, data);
	init_tid_arr(state, data);
	if (*state != ERROR)
		*state = CREATE_THREAD;
}

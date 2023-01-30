/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:59:06 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/30 10:06:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	clear_fork_arr(t_shared_resources *shared_resources)
{
	
}

void	clear(t_state *state, t_rule *rule, \
					t_shared_resources *shared_resources, t_philo *philo_arr)
{
	clear_fork_arr(shared_resources);
	*state = FINISH;
}

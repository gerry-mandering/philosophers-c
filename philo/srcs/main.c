/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:18:47 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 18:01:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_state	state;
	t_data	data;

	state = INIT;
	while (true)
	{
		if (state == INIT)
			init(&state, &data, argc, argv);
		else if (state == CREATE_THREAD)
			create_thread(&state, &data);
		else if (state == MONITORING)
			monitoring(&state, &data);
		else if (state == JOIN_THREAD)
			join_thread(&state, &data);
		else if (state == ERROR)
			error(&state);
		else if (state == FINISH)
			break ;
	}
	return (0);
}

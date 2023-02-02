/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:16:00 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/02 20:33:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <pthread.h>

// function declaration
static void	allocate_tid_arr(enum e_state *state, \
											t_rule *rule, pthread_t **tid_arr);
static void	detach_created_threads(pthread_t *tid_arr, uint64_t size);

void	create_thread(enum e_state *state, \
						t_rule *rule, t_philo *philo_arr, pthread_t **tid_arr)
{
	uint64_t	i;
	int			ret;

	allocate_tid_arr(state, rule, tid_arr);
	if (*state == ERROR)
		return ;
	i = 0;
	while (i < rule->number_of_philosophers)
	{
		//if (philo_arr[i].number % 2 == 0)
			ret = pthread_create(&(*tid_arr)[i], NULL, \
											even_dining_routine, &philo_arr[i]);
		//else
		//	ret = pthread_create(&(*tid_arr)[i], NULL, \
											odd_dining_routine, &philo_arr[i]);
		if (ret != 0)
		{
			detach_created_threads(*tid_arr, i);
			*state = ERROR;
			return ;
		}
		i++;
	}
	*state = MONITORING;
}

static void	allocate_tid_arr(enum e_state *state, \
											t_rule *rule, pthread_t **tid_arr)
{
	*tid_arr = (pthread_t *)ft_malloc(state, sizeof(pthread_t) * \
												rule->number_of_philosophers);
}

static void	detach_created_threads(pthread_t *tid_arr, uint64_t size)
{
	uint64_t	i;

	i = 0;
	while (i < size)
	{
		pthread_detach(tid_arr[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:45:40 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/06 05:09:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_rule(t_state *state, t_rule *rule, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		*state = ERROR;
	rule->number_of_philosophers = ascii_to_ull(state, argv[1]);
	rule->time_to_die = ascii_to_ull(state, argv[2]);
	rule->time_to_eat = ascii_to_ull(state, argv[3]);
	rule->time_to_sleep = ascii_to_ull(state, argv[4]);
	if (argc == 6)
	{
		rule->required_meal_flag = true;
		rule->required_meal_count = ascii_to_ull(state, argv[5]);
	}
}

void	init_shared_data(t_state *state, t_shared_data *shared_data)
{
	if (*state == ERROR)
		return ;
	shared_data->break_flag.state = false;
	ft_pthread_mutex_init(state, &shared_data->break_flag.mutex, NULL);
	ft_pthread_mutex_init(state, &shared_data->start_mutex, NULL);
	//ft_pthread_mutex_init(state, &shared_data->print_mutex, NULL);
}

void	init_fork_arr(t_state *state, t_data *data)
{
	t_fork		*fork_arr;
	uint64_t	i;

	if (*state == ERROR)
		return ;
	fork_arr = (t_fork *)ft_malloc(state, \
			sizeof(t_fork) * data->rule.number_of_philosophers);
	i = 0;
	while (*state != ERROR && i < data->rule.number_of_philosophers)
	{
		fork_arr[i].state = RELEASE;
		ft_pthread_mutex_init(state, &fork_arr[i].mutex, NULL);
		i++;
	}
	data->fork_arr = fork_arr;
}

void	init_philo_arr(t_state *state, t_data *data)
{
	t_philo		*philo_arr;
	uint64_t	i;

	if (*state == ERROR)
		return ;
	philo_arr = (t_philo *)ft_malloc(state, \
						sizeof(t_philo) * data->rule.number_of_philosophers);
	i = 0;
	while (*state != ERROR && i < data->rule.number_of_philosophers)
	{
		philo_arr[i].number = i + 1;
		philo_arr[i].rule = data->rule;
		philo_arr[i].shared_data = &data->shared_data;
		philo_arr[i].left_fork = &data->fork_arr[i];
		if (i == 0)
			philo_arr[i].right_fork = \
						&data->fork_arr[data->rule.number_of_philosophers - 1];
		else
			philo_arr[i].right_fork = &data->fork_arr[i - 1];
		philo_arr[i].dining_info.dining_count = 0;
		ft_pthread_mutex_init(state, &philo_arr[i].dining_info.mutex, NULL);
		i++;
	}
	data->philo_arr = philo_arr;
}

void	init_tid_arr(t_state *state, t_data *data)
{
	if (*state == ERROR)
		return ;
	data->tid_arr = (pthread_t *)ft_malloc(state, \
			sizeof(pthread_t) * data->rule.number_of_philosophers);
}

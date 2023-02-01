/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:14:21 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/01 18:53:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

int	eat(t_philo *philo)
{
	int	ret;

	ret = print_msg(philo, "is eating");
	if (ret != SUCCESS)
		return (ret);
	ft_usleep(philo->rule.time_to_eat);
	return (ret);
}

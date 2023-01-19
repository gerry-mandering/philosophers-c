/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:05:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/19 12:10:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static int	is_digit(const char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}

static uint64_t	make_number(t_state *state, const char *str, int i)
{
	uint64_t	number;

	if (str[i] == '\0')
		return (0);
	if (!is_digit(str[i]))
	{
		*state = ERROR;
		return (0);
	}
	number = str[i] - '0';
	return (number + (10 * make_number(state, str, --i)));
}

uint64_t	ascii_to_ull(t_state *state, const char *str)
{
	uint64_t	number;

	number = make_number(state, str, ft_strlen(str) - 1);
	return (number);
}

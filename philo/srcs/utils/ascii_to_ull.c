/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:46:22 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/07 12:39:46 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static uint64_t	ft_strlen(const char *str)
{
	uint64_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static int	is_digit(char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}

static int	is_overflowed(uint64_t number, const char *str, uint64_t i)
{
	const uint64_t	cutoff = UINT64_MAX / 10;
	const int		cutlim = UINT64_MAX % 10;

	if (number > cutoff && i != ft_strlen(str) - 1)
		return (1);
	else if (number == cutoff && i != ft_strlen(str) - 1 && \
											str[i + 1] - '0' > cutlim)
		return (1);
	else
		return (0);
}

uint64_t	ascii_to_ull(enum e_state *state, const char *str)
{
	uint64_t		number;
	uint64_t		i;

	number = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (!is_digit(str[i]))
		{
			*state = ERROR;
			return (0);
		}
		number *= 10;
		number += str[i] - '0';
		if (is_overflowed(number, str, i))
		{
			*state = ERROR;
			return (UINT64_MAX);
		}
		i++;
	}
	return (number);
}

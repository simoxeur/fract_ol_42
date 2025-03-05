/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoa_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:37:34 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/13 22:30:35 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	atoa_double(char *str)
{
	double	integer;
	double	decimal;
	double	div;
	int		sign;

	integer = 0;
	decimal = 0;
	sign = 1;
	div = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str != '.' && *str)
		integer = integer * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str)
	{
		div /= 10;
		decimal = decimal + (*str++ - '0') * div;
	}
	return (sign * (integer + decimal));
}

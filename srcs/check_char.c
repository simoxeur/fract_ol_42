/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:34:24 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 15:07:37 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_char(char *str)
{
	int	pts;

	pts = 0;
	if (!*str)
		return (-1);
	while (*str == '.' || *str == '+' || *str == '-')
	{
		if (*str == '.')
			pts++;
		str++;
		if (*str == '-' || *str == '+' || *str == '\0')
			return (-1);
	}
	while (*str)
	{
		if (*str == '.')
			pts++;
		else if (*str < '0' || *str > '9')
			return (-1);
		if (pts > 1)
			return (-1);
		str++;
	}
	return (0);
}

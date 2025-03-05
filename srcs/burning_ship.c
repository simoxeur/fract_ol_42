/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:42:03 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 00:38:23 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(int x, int y, t_fractal *fract, int *color)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_color		cl;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, fract->min_x, fract->max_x, WIDTH) + fract->x_move);
	c.y = (scale(y, fract->max_y, fract->min_y, HEIGHT) * 1 + fract->y_move);
	while (i < fract->max_iterations)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z = sum_complex(squar_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			cl = get_color(i, *fract);
			*(int *)color = (cl.t << 24) | (cl.r << 16) | (cl.g << 8) | (cl.b);
			return ;
		}
		i++;
	}
	*color = 0x000000;
	return ;
}

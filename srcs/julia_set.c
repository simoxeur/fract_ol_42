/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:40:18 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 00:15:53 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(int x, int y, t_fractal *fract, int *color)
{
	t_complex	z;
	t_complex	c;
	t_color		col;
	int			i;

	i = 0;
	z.x = (scale(x, fract->min_x, fract->max_x, WIDTH) + fract->x_move);
	z.y = (scale(y, fract->max_y, fract->min_y, HEIGHT) + fract->y_move);
	c.x = fract->julia_x;
	c.y = fract->julia_y;
	while (i < fract->max_iterations)
	{
		z = sum_complex(squar_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			col = get_color(i, *fract);
			*(unsigned int *)color = col.t << 24 | (col.r << 16)
				| (col.g << 8) | (col.b);
			return ;
		}
		i++;
	}
	*color = 0xFFFFFF;
	return ;
}

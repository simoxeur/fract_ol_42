/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:38:23 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 00:26:32 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_set(int x, int y, t_fractal *fract, int *color)
{
	t_complex	z;
	t_complex	c;
	t_color		col;
	int			i;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, fract->min_x, fract->max_x, WIDTH) + fract->x_move);
	c.y = (scale(y, fract->max_y, fract->min_y, HEIGHT) + fract->y_move);
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

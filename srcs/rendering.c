/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:10:53 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 00:28:59 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_topixel(int x, int y, t_fractal *fract, int *color)
{
	if (fract->n == 'm')
		mandelbrot_set(x, y, fract, color);
	if (fract->n == 'j')
		julia_set(x, y, fract, color);
	if (fract->n == 'b')
		burning_ship(x, y, fract, color);
	return ;
}

void	rendring(t_fractal *fract)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			fract_topixel(j, i, fract, &color);
			my_mlx_pixel_put(&fract->img, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img.img, 0, 0);
}

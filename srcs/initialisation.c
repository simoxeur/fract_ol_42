/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:40:43 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 17:49:14 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	image_init(t_fractal *fract)
{
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->mlx_win);
		free(fract->mlx);
		write(2, "error allocate", 14);
		exit(EXIT_FAILURE);
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img,
			&fract->img.bits_per_pixel, &fract->img.line_lenght,
			&fract->img.endian);
}

void	initialisation(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		return ;
	fract->mlx_win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (!fract->mlx)
	{
		free(fract->mlx);
		malloc_fail();
	}
	fract->col.r = 0;
	fract->col.g = 0;
	fract->col.b = 0;
	fract->col.t = 0;
	image_init(fract);
}

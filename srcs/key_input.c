/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:05:04 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 14:52:36 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_view(int key, t_fractal *fract)
{
	if (key == XK_Left)
		fract->x_move -= (0.5 * fract->zoom);
	if (key == XK_Right)
		fract->x_move += (0.5 * fract->zoom);
	if (key == XK_Down && ft_strncmp(fract->name, "burning_ship", 12))
		fract->y_move -= (0.5 * fract->zoom);
	else if (key == XK_Down)
		fract->y_move += (0.5 * fract->zoom);
	if (key == XK_Up && ft_strncmp(fract->name, "burning_ship", 12))
		fract->y_move += (0.5 * fract->zoom);
	else if (key == XK_Up)
		fract->y_move -= (0.5 * fract->zoom);
}

static void	iter_shift(int key, t_fractal *fract)
{
	if (key == XK_p || key == XK_plus)
		fract->max_iterations += 5;
	if (key == XK_minus)
		fract->max_iterations -= 5;
}

static void	reset(t_fractal *fract)
{
	fract->zoom = 1;
	fract->x_move = 0;
	fract->y_move = 0;
	fract->col.r = 0;
	fract->col.g = 0;
	fract->col.b = 0;
	if (ft_strncmp(fract->name, "burning_ship", 12))
	{
		fract->max_x = 2;
		fract->min_x = -2;
		fract->max_y = 2;
		fract->min_y = -2;
	}
	else
	{
		fract->max_x = 1.5;
		fract->min_x = -2.5;
		fract->max_y = -2;
		fract->min_y = 2;
	}
}

void	color_shif(int key, t_fractal *fract)
{
	if (key == XK_r)
		fract->col.r += 10;
	if (key == XK_g)
		fract->col.g += 10;
	if (key == XK_b)
		fract->col.b += 10;
}

int	key_input(int key, t_fractal *fract)
{
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		move_view(key, fract);
	if (key == XK_p || key == XK_plus || key == XK_minus || key == XK_m)
		iter_shift(key, fract);
	if (key == XK_Escape)
		closing(fract);
	if (key == XK_r || key == XK_g || key == XK_b)
		color_shif(key, fract);
	if (key == XK_n)
		reset(fract);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right || key == XK_p
		|| key == XK_plus || key == XK_minus || key == XK_r || key == XK_g || key == XK_b
		|| key == XK_n)
		rendring(fract);
	return (0);
}

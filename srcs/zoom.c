/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:02:21 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 14:06:17 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int button, int x, int y, t_fractal *fract)
{
	double	move_zomex;
	double	move_zomey;
	
	move_zomex = scale(x, fract->min_x, fract->max_x, WIDTH);
	move_zomey = scale(y, fract->max_y, fract->min_y, HEIGHT);
	if (button == 5)
	{
		fract->zoom *= 1.20;
		fract->min_x = move_zomex + 1.20 * (fract->min_x - move_zomex);
		fract->max_x = move_zomex + 1.20 * (fract->max_x - move_zomex);
		fract->min_y = move_zomey + 1.20 * (fract->min_y - move_zomey);
		fract->max_y = move_zomey + 1.20 * (fract->max_y - move_zomey);
	}
	else if (button == 4)
	{
		fract->zoom *= 0.80;
		fract->min_x = move_zomex + 0.80 * (fract->min_x - move_zomex);
		fract->max_x = move_zomex + 0.80 * (fract->max_x - move_zomex);
		fract->min_y = move_zomey + 0.80 * (fract->min_y - move_zomey);
		fract->max_y = move_zomey + 0.80 * (fract->max_y - move_zomey);
	}
	if (button == 4 || button == 5)
		rendring(fract);
	return (0);
}

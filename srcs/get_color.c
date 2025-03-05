/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:16:44 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 00:10:40 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	get_color(double iteration, t_fractal fract)
{
	t_color	color;
	double	t;

	t = iteration / fract.max_iterations;
	color.r = 8 * (1 - t) * (t * t * t * 255) + fract.col.r;
	color.g = 6 * (1 - t) * (1 - t) * t * t * 255 + fract.col.g;
	color.b = 2 * (1 - t) * (1 - t) * (1 - t) * t * 255 + fract.col.b;
	color.t = 255;
	return (color);
}

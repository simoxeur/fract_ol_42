/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:31:33 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 14:36:04 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	limits_init(t_fractal *fract)
{
	if (!ft_strncmp(fract->name, "mandelbrot", 10)
		|| !ft_strncmp(fract->name, "julia", 5))
	{
		fract->min_x = -2;
		fract->max_x = 2;
		fract->min_y = -2;
		fract->max_y = 2;
	}
	else
	{
		fract->max_x = 1.5;
		fract->min_x = -2.5;
		fract->max_y = -2;
		fract->min_y = 2;
	}
}

void	values_init(char **argv, t_fractal *fract)
{
	fract->name = argv[1];
	fract->max_iterations = 30;
	fract->zoom = 1;
	fract->x_move = 0;
	fract->y_move = 0;
	limits_init(fract);
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		if (check_char(argv[2]) == -1 || check_char(argv[3]) == -1)
			return (putstr_fd(ERROR_JULIA, 2), exit(1));
		fract->n = 'j';
		fract->julia_x = atoa_double(argv[2]);
		fract->julia_y = atoa_double(argv[3]);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		fract->n = 'm';
	if (!ft_strncmp(argv[1], "burning_ship", 12))
		fract->n = 'b';
}

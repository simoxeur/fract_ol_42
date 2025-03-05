/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:34:34 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 14:47:10 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 10)
				|| (!ft_strncmp(argv[1], "burning_ship", 12))))
		|| (argc == 4 && !ft_strncmp(argv[1], "Julia", 5)))
	{
		values_init(argv, &fract);
		initialisation(&fract);
		events(&fract);
		rendring(&fract);
		mlx_loop(fract.mlx);
	}
	else
	{
		putstr_fd(ERROR_MSG, 2);
		exit (EXIT_FAILURE);
	}
}

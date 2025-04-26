/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:05:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 14:36:44 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include <mlx.h>
#include "../mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
# include <math.h>
# include "../utils/utils.h"

# define HEIGHT 600
# define WIDTH 600

# define ERROR_MSG "Available :\n\033[0;31m./fractol mandelbrot\n\
\033[0;31m./fractol burning_ship\n\033[0;31m./fractol julia <i> <z>\n"

# define ERROR_JULIA "\033[0;31mFor Julia use real numbers in correct \
way as arguments\n"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}				t_color;

typedef struct s_fractal
{
	char	*name;
	char	n;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		max_iterations;
	double	julia_x;
	double	julia_y;
	double	zoom;
	double	x_move;
	double	y_move;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	t_color	col;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

void		values_init(char **argv, t_fractal *fract);
int			check_char(char *str);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		initialisation(t_fractal *fract);
void		rendring(t_fractal *fract);
void		mandelbrot_set(int x, int y, t_fractal *fract, int *color);
void		julia_set(int x, int y, t_fractal *fract, int *color);
void		burning_ship(int x, int y, t_fractal *fract, int *color);
t_complex	squar_complex(t_complex z);
t_complex	sum_complex(t_complex z, t_complex c);
double		scale(double unsc, double new_min, double new_max, double old_max);
void		events(t_fractal *fract);
int			closing(t_fractal *fract);
int			zoom(int button, int x, int y, t_fractal *fract);
int			key_input(int key, t_fractal *fract);
t_color		get_color(double iteration, t_fractal fract);

#endif
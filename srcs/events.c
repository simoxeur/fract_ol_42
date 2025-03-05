/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:58:19 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 22:47:57 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask, zoom, fract);
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, key_input, fract);
	mlx_hook(fract->mlx_win, DestroyNotify, SubstructureNotifyMask, closing, fract);
}

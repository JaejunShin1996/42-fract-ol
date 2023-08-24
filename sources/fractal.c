/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:48:22 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/24 17:30:12 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fractol *f)
{
	int		i;
	double	temp;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x * f->zoom) - f->offset_x;
	f->cy = (f->y * f->zoom) - f->offset_y;
	while (i < MAX_ITERATION)
	{
		temp = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = (2. * f->zx * f->zy) + f->cy;
		f->zx = temp;
		if ((f->zx * f->zx) + (f->zy * f->zy) >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == MAX_ITERATION)
		put_colour_to_pixel(f, f->x, f->y, BLACK);
	else
		put_colour_to_pixel(f, f->x, f->y, (f->colour * i));
}

void	draw_fractol(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		f->y = 0;
		while (f->y < SIZE)
		{
			mandelbrot(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

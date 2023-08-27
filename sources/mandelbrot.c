/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:17:14 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/27 15:13:54 by jaeshin          ###   ########.fr       */
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
	f->cx = f->x / f->zoom + f->offset_x;
	f->cy = f->y / f->zoom + f->offset_y;
	while (i < MAX_ITERATION)
	{
		temp = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy;
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

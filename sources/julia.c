/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:17:59 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/27 15:13:59 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_fractol *f, double cx, double cy)
{
	int		i;
	double	temp;

	i = 0;
	f->cx = cx;
	f->cy = cy;
	f->zx = f->x / f->zoom + (f->offset_x + 0.65);
	f->zy = f->y / f->zoom + (f->offset_y);
	while (i < MAX_ITERATION)
	{
		temp = f->zx;
		f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = 2 * f->zy * temp + f->cy;
		if ((f->zx * f->zx) + (f->zy * f->zy) >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == MAX_ITERATION)
		put_colour_to_pixel(f, f->x, f->y, BLACK);
	else
		put_colour_to_pixel(f, f->x, f->y, (f->colour * i));
}

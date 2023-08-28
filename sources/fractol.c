/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:13:04 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/28 11:31:26 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractol(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	mlx_clear_window(f->mlx, f->win);
	while (f->x < SIZE)
	{
		f->y = 0;
		while (f->y < SIZE)
		{
			if (ft_strncmp("mandelbrot", f->option, 11) == 0)
				mandelbrot(f);
			else if (ft_strncmp("julia", f->option, 6) == 0)
				julia(f, -0.535429, 0.52);
			else if (ft_strncmp("julia2", f->option, 7) == 0)
				julia(f, 0.37429, -0.314352);
			else if (ft_strncmp("burningShip", f->option, 12) == 0)
				burning_ship(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

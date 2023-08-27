/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:15:59 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/27 16:13:29 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_f(t_fractol *f, char *option)
{
	if (!f)
		exit(0);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, SIZE, SIZE, option);
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->info_img = mlx_get_data_addr(f->img, &f->bits_per_piexl, &f->size_line, &f->endian);
	f->option = option;
	f->x = 0;
	f->y = 0;
	f->offset_x = -2.00;
	f->offset_y = -1.35;
	f->zoom = SIZE * 0.37;
	f->colour = COLOUR1;
}

void	input_error(char *input)
{
	if ((ft_strncmp("mandelbrot", input, 11) != 0) &&
		(ft_strncmp("julia", input, 6) != 0) &&
		(ft_strncmp("burningShip", input, 12) != 0))
	{
		ft_printf("Available sets are mandelbrot, julia or burningShip\n");
		exit(0);
	}
}

int	exit_fractol(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
	free(f);
	exit(0);
	return (0);
}

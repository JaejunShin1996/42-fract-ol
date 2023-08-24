/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:15:59 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/24 16:43:07 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_f(t_fractol *f, char *argv)
{
	if (!f)
		exit(0);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, SIZE, SIZE, argv);
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->info_img = mlx_get_data_addr(f->img, &f->bits_per_piexl, &f->size_line, &f->endian);
	f->x = 0;
	f->y = 0;
	f->offset_x = 2.25;
	f->offset_y = 1.55;
	f->zoom = 0.0029;
	f->colour = BEIGE;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:15:59 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/22 20:23:17 by jaeshin          ###   ########.fr       */
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
	printf("size line - %d, bits - %d, endian - %d\n", f->size_line, f->bits_per_piexl, f->endian);
	f->x = 0;
	f->y = 0;
}

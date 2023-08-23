/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:45:41 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/23 21:17:05 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_fractol(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
	free(f);
	exit(0);
	return (0);
}

int	key_handler(int keycode)
{
	if (keycode == ESC)
		exit(1);
	return (0);
}

// void	zoom(t_fractol *f, int x, int y, int zoom)
// {
// 	double	zoom_level;
// }

int	mouse_handler(int button, int x, int y)
{
	ft_printf("Mouse button %i, Position (%i, %i)\n", button, x, y);
	return (0);
}

void	put_color_to_pixel(t_fractol *f, int x, int y, int colour)
{
	int	*info_img;

	info_img = f->info_img;
	// okay...but why divide by 4??????? - 4 bytes
	info_img[y * f->size_line / 4 + x] = colour;
}

void	draw_fractol(t_fractol *f)
{
	f->x = SIZE * 0.333;
	while (f->x < SIZE * 0.666)
	{
		f->y = SIZE * 0.333;
		while (f->y < SIZE * 0.666)
		{
			put_color_to_pixel(f, f->x, f->y, 0xffff00);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc != 2)
		return (0);
	f = malloc(sizeof(t_fractol));
	init_f(f, argv[1]);
	mlx_key_hook(f->win, key_handler, f->mlx);
	mlx_mouse_hook(f->win, mouse_handler, f->mlx);
	mlx_hook(f->win, 17, 0L, exit_fractol, f);
	draw_fractol(f);
	mlx_loop(f->mlx);
	return (0);
}

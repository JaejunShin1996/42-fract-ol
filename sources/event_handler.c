/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:41:21 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/28 11:14:46 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(t_fractol *f, int move)
{
	if (move == LEFT)
		f->offset_x -= 60 / f->zoom;
	else if (move == RIGHT)
		f->offset_x += 60 / f->zoom;
	else if (move == DOWN)
		f->offset_y += 60 / f->zoom;
	else if (move == UP)
		f->offset_y -= 60 / f->zoom;
}

void	zoom(t_fractol *f, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.2;
	if (zoom == ZOOM_IN)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x
				/ (f->zoom * zoom_level));
		f->offset_y = (y / f->zoom + f->offset_y) - (y 
				/ (f->zoom * zoom_level));
		f->zoom *= zoom_level;
	}
	else if (zoom == ZOOM_OUT)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x 
				/ (f->zoom / zoom_level));
		f->offset_y = (y / f->zoom + f->offset_y) - (y 
				/ (f->zoom / zoom_level));
		f->zoom /= zoom_level;
	}
}

int	key_handler(int keycode, t_fractol *f)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == SPACE)
		change_colour(f);
	else if (keycode == LEFT)
		move(f, LEFT);
	else if (keycode == RIGHT)
		move(f, RIGHT);
	else if (keycode == DOWN)
		move(f, DOWN);
	else if (keycode == UP)
		move(f, UP);
	draw_fractol(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	if (button == ZOOM_IN)
		zoom(f, x, y, ZOOM_IN);
	else if (button == ZOOM_OUT)
		zoom(f, x, y, ZOOM_OUT);
	draw_fractol(f);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:41:21 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/24 17:31:59 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	if (button == ZOOM_IN)
		zoom(f, x, y, 1);
	else if (button == ZOOM_OUT)
		zoom(f, x, y, 2);
	draw_fractol(f);
	return (0);
}

void	zoom(t_fractol *f, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.3;
	if (zoom == 1)
	{
		// fix zoom
		f->offset_x = x + 0.01;
		f->offset_x = y + 0.01;
		f->zoom *= zoom_level;
	}
	else if (zoom == 2)
	{
		// fix zoom
		f->offset_x = x - 0.01;
		f->offset_x = y - 0.01;
		f->zoom /= zoom_level;
	}
}

int	key_handler(int keycode, t_fractol *f)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == SPACE)
		change_colour(f);
	draw_fractol(f);
	return (0);
}

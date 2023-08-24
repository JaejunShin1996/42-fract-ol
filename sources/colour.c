/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:43:28 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/24 16:28:17 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_colour(t_fractol *f)
{
	if (f->colour == COBALT_BLUE)
		f->colour = BEIGE;
	else if (f->colour == BEIGE)
		f->colour = NAVAJO_WHITE;
	else if (f->colour == NAVAJO_WHITE)
		f->colour = BABY_BLUE;
	else if (f->colour == BABY_BLUE)
		f->colour = COBALT_BLUE;
}

void	put_colour_to_pixel(t_fractol *f, int x, int y, int colour)
{
	int	*info_img;

	info_img = f->info_img;
	info_img[y * f->size_line / 4 + x] = colour;
}

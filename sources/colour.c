/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:43:28 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/27 15:05:59 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_colour(t_fractol *f)
{
	if (f->colour == COLOUR4)
		f->colour = COLOUR1;
	else if (f->colour == COLOUR1)
		f->colour = COLOUR2;
	else if (f->colour == COLOUR2)
		f->colour = COLOUR3;
	else if (f->colour == COLOUR3)
		f->colour = COLOUR4;
}

void	put_colour_to_pixel(t_fractol *f, int x, int y, int colour)
{
	int	*info_img;

	info_img = f->info_img;
	info_img[y * f->size_line / 4 + x] = colour;
}

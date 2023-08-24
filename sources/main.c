/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:45:27 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/24 16:11:10 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc != 2)
		return (0);
	f = malloc(sizeof(t_fractol));
	init_f(f, argv[1]);
	mlx_key_hook(f->win, key_handler, f);
	mlx_mouse_hook(f->win, mouse_handler, f);
	mlx_hook(f->win, 17, 0L, exit_fractol, f);
	draw_fractol(f);
	mlx_loop(f->mlx);
	return (0);
}

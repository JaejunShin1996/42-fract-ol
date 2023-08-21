/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:45:41 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/21 19:48:40 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_keys(int keycode, void *mlx_ptr, void *window_ptr)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_ptr, window_ptr);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	void	*connection;
	void	*window;
	float	x;
	float	y;
	int		result;

	x = 900 * 0.333;
	y = 900 * 0.333;
	result = 0;
	connection = mlx_init();
	if (connection)
		ft_printf("Connection successfully created! %d, %s\n", argc, argv[0]);
	window = mlx_new_window(connection, 900, 900, argv[1]);
	if (window)
		ft_printf("Window successfully created! %p\n", window);
	while (x < 900 * 0.666)
	{
		y = 900 * 0.333;
		while (y < 900 * 0.666)
		{
			result = mlx_pixel_put(connection, window, x, y, 0xffff00);
			ft_printf("result - %d\n", result);
			y++;
		}
		x++;
	}
	mlx_key_hook(window, handle_keys, connection);
	mlx_loop(connection);
	return (0);
}

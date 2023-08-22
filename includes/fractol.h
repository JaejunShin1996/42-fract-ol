/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:40:17 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/22 20:15:40 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

// SIZE
# define SIZE 900

// KEYCODES
# define ESC 53

// MOUSECODES
# define ZOOM_OUT 4
# define ZOOM_IN 5

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*info_img;
	int		bits_per_piexl;
	int		size_line;
	int		endian;
	double	x;
	double	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
}	t_fractol;

// Initialise
void	init_f(t_fractol *f, char *argv);

#endif
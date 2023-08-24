/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:40:17 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/24 17:23:47 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

// Size
# define SIZE 1080
# define MAX_ITERATION 500

// Keycodes
# define ESC 53
# define SPACE 49

// Mousecodes
# define ZOOM_OUT 4
# define ZOOM_IN 5

// Colours
# define BLACK 0x000000
# define BEIGE 0xF5F5DC
# define NAVAJO_WHITE 0xE2DFD2
# define BABY_BLUE 0xFAF9F6
# define COBALT_BLUE 0x0047AB

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
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		colour;
}	t_fractol;

// Initialise
void	init_f(t_fractol *f, char *argv);
int		exit_fractol(t_fractol *f);

// Event
int		mouse_handler(int button,int x, int y, t_fractol *f);
int		key_handler(int keycode, t_fractol *f);
void	zoom(t_fractol *f, int x, int y, int zoom);

// Colour
void	change_colour(t_fractol *f);
void	put_colour_to_pixel(t_fractol *f, int x, int y, int colour);

// Fractal
void	mandelbrot(t_fractol *f);
void	draw_fractol(t_fractol *f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:40:17 by jaeshin           #+#    #+#             */
/*   Updated: 2023/08/27 16:12:28 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <math.h>

// Size
# define SIZE 900
# define MAX_ITERATION 40

// Keycodes
# define ESC 53
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

// Mousecodes
# define LMB 1
# define RMB 2
# define ZOOM_OUT 4
# define ZOOM_IN 5

// Colours
# define BLACK 0x000000
# define COLOUR1 0x202020
# define COLOUR2 0x404040
# define COLOUR3 0x606060
# define COLOUR4 0x808080

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*info_img;
	int		bits_per_piexl;
	int		size_line;
	int		endian;
	char	*option;
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
void	input_error(char *input);
int		exit_fractol(t_fractol *f);

// Event
int		mouse_handler(int button,int x, int y, t_fractol *f);
int		key_handler(int keycode, t_fractol *f);
void	zoom(t_fractol *f, int x, int y, int zoom);
void	move(t_fractol *f, int move);

// Colour
void	change_colour(t_fractol *f);
void	put_colour_to_pixel(t_fractol *f, int x, int y, int colour);

// Fractal
void	mandelbrot(t_fractol *f);
void	julia(t_fractol *f, double cx, double cy);
void	burning_ship(t_fractol *f);
void	draw_fractol(t_fractol *f);

#endif

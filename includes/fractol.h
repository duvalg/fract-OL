/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:16:07 by gduval            #+#    #+#             */
/*   Updated: 2018/01/04 11:16:08 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <pthread.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_bonus
{
	long double			iteration_max;
	long double			win_height;
	long double			win_width;
	long double			zoom;
	long double			zoom_add;
	long double			var;
}					t_bonus;

typedef struct		s_image
{
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct		s_core
{
	pthread_t 		core_one;
	pthread_t 		core_two;
}					t_core;

typedef struct		s_dna
{
	void			*win;
	void			*mlx;
	int				(*f[6]) (int, struct s_dna *);
	long double		x1;
	long double		y1;
	long double		x2;
	long double		y2;
	long double		h;
	int				mouse_x;
	int				mouse_y;
	int				fractale;
	int				variation;
	t_image			*image;
	t_bonus			*bonus;
	t_core			*core;
}					t_dna;

int			main(int ac, char **av);
void		init_dna(int type);
int			init_mlx(t_dna *dna);
int			pos_gestion(int keycode, t_dna *dna);
int			iteration_gestion(int keycode, t_dna *dna);
int			zoom_gestion(int keycode, t_dna *dna);
int			variation_gestion(int keycode, t_dna *dna);
void		mlx_pixel_put_to_image(t_dna *dna, int *x, int *y, int color);
void		*draw_julia(t_dna *dna);
int			draw_mandelbrot(t_dna *dna);
int			draw_tricorn(t_dna *dna);
int			reset(int keycode, t_dna *dna);
int			exit_program(int keycode, t_dna *dna);
void		init_pos(t_dna *dna);

#endif

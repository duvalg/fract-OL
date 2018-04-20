/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:16:07 by gduval            #+#    #+#             */
/*   Updated: 2018/01/23 12:55:42 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600

# define THREADS 20

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# include <pthread.h>
# include <math.h>

typedef struct		s_bonus
{
	long double		iteration_max;
	long double		win_height;
	long double		win_width;
	long double		zoom;
	long double		zoom_add;
	float			var;
	int				variation;
	int				perspective;
}					t_bonus;

typedef struct		s_image
{
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct		s_coords
{
	long double		x1;
	long double		y1;
	long double		x2;
	long double		y2;
	long double		h;
	int				mouse_x;
	int				mouse_y;
}					t_coords;

typedef struct		s_dna
{
	void			*win;
	void			*mlx;
	int				fractale;
	int				get_core;
	int				(*f[9]) (int, struct s_dna *);
	void			*(*display[4]) (void *);
	pthread_t		core[THREADS];
	t_coords		*coords;
	t_image			*image;
	t_bonus			*bonus;
}					t_dna;

int					main(int ac, char **av);
void				init_dna(int type);
int					init_mlx(t_dna *dna);
void				init_func_array(t_dna *dna);
int					keyhook(int keycode, void *param);
int					mouse_hook(int keycode, int x, int y, void *param);
int					mouse_position(int x, int y, void *param);
int					pos_gestion(int keycode, t_dna *dna);
int					iteration_gestion(int keycode, t_dna *dna);
int					zoom_gestion(int keycode, t_dna *dna);
int					variation_gestion(int keycode, t_dna *dna);
int					var_gestion(int keycode, t_dna *dna);
int					perspective_gestion(int keycode, t_dna *dna);
void				mlx_pixel_put_to_image(t_dna *dna, int *x, int *y, \
	int color);
int					fractal_gestion(int keycode, t_dna *dna);
void				*draw_julia(void *data);
void				*draw_mandelbrot(void *data);
void				*draw_tricorn(void *data);
void				bresenham(double x, double y, double xf, double yf, \
	t_dna *dna);
unsigned int		get_thread(pthread_t id, pthread_t *threads);
void				draw_fractal(t_dna *dna);
int					reset(int keycode, t_dna *dna);
void				error(const char *str);
int					exit_program(int keycode, t_dna *dna);
void				init_pos(t_dna *dna);

#endif

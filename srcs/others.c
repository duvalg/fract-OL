/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:11 by gduval            #+#    #+#             */
/*   Updated: 2018/01/15 13:11:50 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			error(const char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	ft_putendl_fd("usage:\t./fractol \
[julia | mandelbrot | tricorn | burningship]"\
	, 2);
	exit(EXIT_FAILURE);
}

void			init_func_array(t_dna *dna)
{
	dna->f[0] = &pos_gestion;
	dna->f[1] = &iteration_gestion;
	dna->f[2] = &zoom_gestion;
	dna->f[3] = &reset;
	dna->f[4] = &variation_gestion;
	dna->f[5] = &fractal_gestion;
	dna->f[6] = &var_gestion;
	dna->f[7] = &perspective_gestion;
	dna->f[8] = &exit_program;
	dna->display[0] = &draw_julia;
	dna->display[1] = &draw_mandelbrot;
	dna->display[2] = &draw_tricorn;
	dna->display[3] = &draw_mandelbrot;
	init_mlx(dna);
}

void			init_pos(t_dna *dna)
{
	dna->coords->x1 = -2.9999;
	dna->coords->y1 = -2.9999;
	dna->coords->x2 = 5;
	dna->coords->y2 = 5;
}

void			draw_fractal(t_dna *dna)
{
	int		i;

	i = -1;
	dna->get_core = -1;
	while (++i < THREADS)
		pthread_create(&dna->core[i], NULL, dna->display[dna->fractale], dna);
	i = -1;
	while (++i < THREADS)
		pthread_join(dna->core[i], NULL);
	mlx_put_image_to_window(dna->mlx, dna->win, dna->image->image_ptr, 0, 0);
}

unsigned int	get_thread(pthread_t id, pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < THREADS && !pthread_equal(id, threads[i]))
		;
	return (i);
}

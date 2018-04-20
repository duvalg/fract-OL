/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:35:43 by gduval            #+#    #+#             */
/*   Updated: 2018/01/08 10:35:44 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_julia(long double c_r, int x, int y, t_dna *dna)
{
	long double tmp;
	long double z_r;
	long double z_i;
	long double i;

	z_r = x / dna->bonus->zoom + dna->coords->x1;
	z_i = y / dna->bonus->zoom + dna->coords->y1;
	i = 0;
	while (i < dna->bonus->iteration_max && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + 0.01;
		++i;
		if (i == dna->bonus->iteration_max)
			mlx_pixel_put_to_image(dna, &x, &y, 0x122440);
		else if (i != dna->bonus->iteration_max)
			mlx_pixel_put_to_image(dna, &x, &y, 0x122440 * i);
	}
}

static void	calc_julia(long double image_x, long double image_y, t_dna *dna)
{
	int	x;
	int	y;
	int	padding;
	int	start;

	padding = WIDTH / THREADS;
	start = padding * get_thread(pthread_self(), (pthread_t *)dna->core);
	x = start - 1;
	while (++x < image_x && x < WIDTH && x < start + padding)
	{
		y = -1;
		while (++y < image_y && y < HEIGHT)
			print_julia(dna->bonus->var, x, y, dna);
	}
}

void		*draw_julia(void *data)
{
	long double	image_x;
	long double	image_y;
	t_dna		*dna;

	dna = (t_dna *)data;
	image_x = (dna->coords->x2 - dna->coords->x1) * dna->bonus->zoom;
	image_y = (dna->coords->y2 - dna->coords->y1) * dna->bonus->zoom;
	calc_julia(image_x, image_y, dna);
	pthread_exit(NULL);
	return (NULL);
}

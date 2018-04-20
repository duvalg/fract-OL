/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tricorn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:25:21 by gduval            #+#    #+#             */
/*   Updated: 2018/01/11 13:25:22 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_tricorn(int *coords, long double c_r, long double c_i, \
t_dna *dna)
{
	long double tmp;
	long double z_i;
	long double z_r;
	long long	i;

	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < dna->bonus->iteration_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = -2 * z_i * tmp + c_i;
		++i;
	}
	if (i == dna->bonus->iteration_max)
		mlx_pixel_put_to_image(dna, &coords[0], &coords[1], 0x122440);
	else if (i > 1)
		mlx_pixel_put_to_image(dna, &coords[0], &coords[1], 0x122440 * i);
}

static void	calc_tricorn(long double *xy, long double image_x, \
long double image_y, t_dna *dna)
{
	long double	zoom[2];
	int			padding;
	int			start;
	int			coords[2];

	zoom[0] = image_x / (xy[0] - dna->coords->x1);
	zoom[1] = image_y / (xy[1] - dna->coords->y1);
	padding = WIDTH / THREADS;
	start = padding * get_thread(pthread_self(), (pthread_t *)dna->core);
	coords[0] = start - 1;
	while (++coords[0] < image_x && coords[0] <= WIDTH \
		&& coords[0] < start + padding)
	{
		coords[1] = -1;
		while (++coords[1] < image_y && coords[1] <= HEIGHT)
			print_tricorn((int *)coords, coords[0] / zoom[0] + dna->coords->x1,\
			coords[1] / zoom[1] + dna->coords->y1, dna);
	}
}

void		*draw_tricorn(void *data)
{
	long double	xy[2];
	t_dna		*dna;

	dna = (t_dna *)data;
	xy[0] = 2;
	xy[1] = 2;
	calc_tricorn((long double *)xy, (xy[0] - dna->coords->x1) * \
	dna->bonus->zoom, (xy[1] - dna->coords->y1) * dna->bonus->zoom, dna);
	return (NULL);
}

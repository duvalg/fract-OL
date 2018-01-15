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

void		*draw_julia(t_dna *dna)
{
	long double	x1 = dna->x1;
	long double	x2 = dna->x2;
	long double	y1 = dna->y1;
	long double	y2 = dna->y2;
	long double	zoom = dna->bonus->zoom;
	long double	iteration_max = dna->bonus->iteration_max;
	long double	image_x = (x2 - x1) * zoom;
	long double	image_y = (y2 - y1) * zoom;
	int		x = 0;
	int		y;
	long double 	tmp;

	while (x < image_x && x <= WIDTH)
	{
		y = 0;
		while (y < image_y && y <= HEIGHT)
		{
			long double c_r = dna->bonus->var;
	        long double c_i = 0.01;
	        long double z_r = x / zoom + x1;
	        long double z_i = y / zoom + y1;
	        long double i = 0;

	        while (z_r * z_r + z_i * z_i < 4 && i < iteration_max)
			{
				tmp = z_r;

	            z_r = z_r * z_r - z_i * z_i + c_r;
	            z_i = 2 * z_i * tmp + c_i;
	            i += 1;
				if (i == iteration_max)
					mlx_pixel_put_to_image(dna, &x, &y, 0x122440);
				else if (i > 10)
					mlx_pixel_put_to_image(dna, &x, &y, 0x122440 * i);
			}
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(dna->mlx, dna->win, dna->image->image_ptr, 0, 0);
	return (NULL);
}

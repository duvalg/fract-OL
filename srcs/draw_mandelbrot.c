/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrolt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:35:56 by gduval            #+#    #+#             */
/*   Updated: 2018/01/08 10:35:57 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			draw_mandelbrot(t_dna *dna)
{
	long double	x1 = dna->x1;
	long double	y1 = dna->y1;
	long double	x2 = 2;
	long double	y2 = 2;
	long double	image_x = (x2 - x1) * dna->bonus->zoom;
	long double	image_y = (y2 - y1) * dna->bonus->zoom;
	int		x = 0;
	int		y;
	long double	zoom_x = image_x / (x2 - x1);
	long double	zoom_y = image_y / (y2 - y1);

	while (x < image_x && x <= WIDTH)
	{
		y = 0;
		while (y < image_y && y <= HEIGHT)
		{
			long double c_r = x / zoom_x + x1;
	        long double c_i = y / zoom_y + y1;
	        long double z_r = 0;
	        long double z_i = 0;
	        long double i = 0;

	        while (z_r * z_r + z_i * z_i < 4 && i < dna->bonus->iteration_max)
			{
	            long double tmp = z_r;

	            z_r = z_r * z_r - z_i * z_i + c_r;
	            z_i = 2 * z_i * tmp + c_i;
	            i = i + 1;
	        }
	        if (i == dna->bonus->iteration_max)
	            mlx_pixel_put_to_image(dna, &x, &y, 0x122440);
	        else if (i >1)
	            mlx_pixel_put_to_image(dna, &x, &y, 0x122440 * i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(dna->mlx, dna->win, dna->image->image_ptr, 0, 0);
	return (0);
}

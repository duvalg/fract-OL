/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:13:12 by gduval            #+#    #+#             */
/*   Updated: 2018/03/14 17:13:13 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				keyhook(int keycode, void *param)
{
	t_dna		*dna;
	int			i;

	i = -1;
	dna = (t_dna *)param;
	while (++i < 9 && !dna->f[i](keycode, dna))
		;
	mlx_destroy_image(dna->mlx, dna->image->image_ptr);
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	draw_fractal(dna);
	return (0);
}

int				mouse_hook(int keycode, int x, int y, void *param)
{
	t_dna		*dna;

	dna = (t_dna *)param;
	if ((keycode == 1 || keycode == 4) && y >= 0)
	{
		dna->coords->x1 += (((float)x - (WIDTH / 2)) / dna->bonus->zoom);
		dna->coords->y1 += (((float)y - (HEIGHT / 2)) / dna->bonus->zoom);
		dna->bonus->zoom *= 1.2;
	}
	else if ((keycode == 2 || keycode == 5) && y >= 0)
	{
		dna->coords->x1 += (((float)x - (WIDTH / 2)) / dna->bonus->zoom);
		dna->coords->y1 += (((float)y - (HEIGHT / 2)) / dna->bonus->zoom);
		dna->bonus->zoom *= 0.9;
	}
	mlx_destroy_image(dna->mlx, dna->image->image_ptr);
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	draw_fractal(dna);
	return (0);
}

int				mouse_position(int x, int y, void *param)
{
	t_dna		*dna;

	dna = (t_dna *)param;
	if (x < WIDTH && x > 0 && dna->bonus->variation)
	{
		if (y < HEIGHT && y > 0)
		{
			dna->bonus->var = 0.285 + (((float)x / 2 * (float)y / 2) / 100000);
			mlx_destroy_image(dna->mlx, dna->image->image_ptr);
			dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
			draw_fractal(dna);
		}
	}
	return (0);
}

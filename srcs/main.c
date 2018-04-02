/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:17:49 by gduval            #+#    #+#             */
/*   Updated: 2018/01/04 11:17:51 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		keyhook(int keycode, void *param)
{
	t_dna	*dna;
	int		i;

	i = -1;
	dna = (t_dna *)param;

	while (++i < 6 && !dna->f[i](keycode, dna))
		;
	mlx_destroy_image(dna->mlx, dna->image->image_ptr);
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
		&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
	if (dna->fractale == 1)
		draw_julia(dna);
	else if (dna->fractale == 2)
		draw_mandelbrot(dna);
	else if (dna->fractale == 3)
		draw_tricorn(dna);
	return (0);
}

static int		mouse_hook(int keycode, int x, int y, void *param)
{
	t_dna		*dna;

	dna = (t_dna *)param;
	if ((keycode == 1 || keycode == 4) && y >= 0)
	{
		dna->x1 += (((float)x - (WIDTH / 2)) / dna->bonus->zoom);
		dna->y1 += (((float)y - (HEIGHT / 2)) / dna->bonus->zoom);
		dna->bonus->zoom *= 1.2;
	}
	else if ((keycode == 2 || keycode == 5) && y >= 0)
	{
		dna->x1 += (((float)x - (WIDTH / 2)) / dna->bonus->zoom);
		dna->y1 += (((float)y - (HEIGHT / 2)) / dna->bonus->zoom);
		dna->bonus->zoom *= 0.9;
	}
	mlx_destroy_image(dna->mlx, dna->image->image_ptr);
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
		&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
	if (dna->fractale == 1)
		draw_julia(dna);
	else if (dna->fractale == 2)
		draw_mandelbrot(dna);
	else if (dna->fractale == 3)
		draw_tricorn(dna);
	return (0);
}

static int		mouse_position(int x, int y, void *param)
{
	t_dna		*dna;

	dna = (t_dna *)param;
	if (x < WIDTH && x > 0 && dna->variation)
	{
		if (y < HEIGHT && y > 0)
		{
			dna->bonus->var = 0.285 + (((float)x / 2 * (float)y / 2) / 100000);
			mlx_destroy_image(dna->mlx, dna->image->image_ptr);
			dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
			dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
				&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
			if (dna->fractale == 1)
				draw_julia(dna);
			else if (dna->fractale == 2)
				draw_mandelbrot(dna);
			else if (dna->fractale == 3)
				draw_tricorn(dna);
		}
	}
	return (0);
}

int				init_mlx(t_dna *dna)
{
	dna->mlx = mlx_init();
	dna->win = mlx_new_window(dna->mlx, WIDTH, HEIGHT, "display window");
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
		&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
	mlx_hook(dna->win, 2, (1L << 0), keyhook, dna);
	mlx_hook(dna->win, 6, (1L << 6), mouse_position, dna);
	mlx_mouse_hook(dna->win, mouse_hook, dna);
	if (dna->fractale == 1)
		draw_julia(dna);
	else if (dna->fractale == 2)
		draw_mandelbrot(dna);
	else if (dna->fractale == 3)
		draw_tricorn(dna);
	mlx_loop(dna->mlx);
	return (1);
}

int				main(int ac, char **av)
{
	int		type;

	type = 0;
	if (ac != 2)
		return (3);
	else
	{
		if (!ft_strcmp(av[1], "julia"))
			type = 1;
		else if (!ft_strcmp(av[1], "mandelbrot"))
			type = 2;
		else if (!ft_strcmp(av[1], "tricorn"))
			type = 3;
		else
			return (3);
	}
	init_dna(type);
	return (0);
}

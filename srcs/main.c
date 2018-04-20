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

int				init_mlx(t_dna *dna)
{
	dna->mlx = mlx_init();
	dna->win = mlx_new_window(dna->mlx, WIDTH, HEIGHT, "Fractol");
	dna->image->image_ptr = mlx_new_image(dna->mlx, WIDTH, HEIGHT);
	dna->image->image = mlx_get_data_addr(dna->image->image_ptr, \
		&dna->image->bpp, &dna->image->line_length, &dna->image->endian);
	mlx_hook(dna->win, 2, (1L << 0), keyhook, dna);
	if (dna->fractale == 0 || dna->fractale == 1)
		mlx_hook(dna->win, 6, (1L << 6), mouse_position, dna);
	mlx_mouse_hook(dna->win, mouse_hook, dna);
	draw_fractal(dna);
	mlx_loop(dna->mlx);
	return (1);
}

int				main(int ac, char **av)
{
	int		type;

	type = 0;
	if (ac != 2)
		error(NULL);
	else if (THREADS < 1)
		error("error:\twrong number of threads\n\t\
		edit THREADS define at includes/fractol.h (l.18)");
	else
	{
		if (!ft_strcmp(av[1], "julia"))
			type = 0;
		else if (!ft_strcmp(av[1], "mandelbrot"))
			type = 1;
		else if (!ft_strcmp(av[1], "tricorn"))
			type = 2;
		else if (!ft_strcmp(av[1], "burningship"))
			type = 3;
		else
			error(NULL);
	}
	init_dna(type);
	return (0);
}

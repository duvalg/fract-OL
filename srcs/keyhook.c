/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:14:55 by gduval            #+#    #+#             */
/*   Updated: 2018/01/04 18:14:56 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		iteration_gestion(int keycode, t_dna *dna)
{
	if (keycode == 116 || keycode == 121)
	{
		if (keycode == 121)
		{
			if (dna->bonus->iteration_max > 2)
				--dna->bonus->iteration_max;
		}
		else
			++dna->bonus->iteration_max;
		return (1);
	}
	return (0);
}

int		variation_gestion(int keycode, t_dna *dna)
{
	if (keycode == 9)
	{
		dna->bonus->variation = (dna->bonus->variation == 0) ? 1 : 0;
		return (1);
	}
	return (0);
}

int		zoom_gestion(int keycode, t_dna *dna)
{
	if (keycode != 69 && keycode != 78)
		return (0);
	dna->coords->h = (keycode == 78) ? \
	dna->coords->h - 10 : dna->coords->h + 10;
	return (1);
}

int		reset(int keycode, t_dna *dna)
{
	if (keycode != 82)
		return (0);
	init_pos(dna);
	dna->bonus->win_height = HEIGHT;
	dna->bonus->win_width = WIDTH;
	dna->bonus->iteration_max = 50;
	dna->bonus->var = 0.285;
	dna->bonus->zoom = 100;
	return (1);
}

int		exit_program(int keycode, t_dna *dna)
{
	if (keycode == 53 && dna)
	{
		mlx_destroy_image(dna->mlx, dna->image->image_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

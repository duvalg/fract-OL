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

int		pos_gestion(int keycode, t_dna *dna)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		return (0);
	else
	{
		printf("x1-> %Lf - y1-> %Lf\n\n", dna->x1, dna->y1);
		if (keycode == 123 || keycode == 124)
			dna->x1 = (keycode == 124) ? dna->x1 - 0.1 : dna->x1 + 0.1;
		else if (keycode == 125 || keycode == 126)
			dna->y1 = (keycode == 125) ? dna->y1 - 0.1 : dna->y1 + 0.1;
		return (1);
	}
	return (0);
}

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
		dna->variation = (dna->variation == 0) ? 1 : 0;
		return (1);
	}
	return (0);
}

int		zoom_gestion(int keycode, t_dna *dna)
{
	if (keycode != 69 && keycode != 78)
		return (0);
	dna->h = (keycode == 78) ? dna->h - 10 : dna->h + 10;
	// printf("h-> %f\n", dna->h);
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

int			exit_program(int keycode, t_dna *dna)
{
	if (keycode == 53 && dna)
		exit(EXIT_SUCCESS);
	return (0);
}

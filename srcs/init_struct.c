/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:24:48 by gduval            #+#    #+#             */
/*   Updated: 2018/01/04 16:24:49 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_bonus(t_dna *dna)
{
	t_bonus		bonus;

	bonus.iteration_max = 50;
	bonus.win_height = 0;
	bonus.win_width = WIDTH;
	bonus.win_height = HEIGHT;
	bonus.zoom = 100;
	bonus.zoom_add = 100;
	bonus.var = 0.285;
	bonus.variation = 0;
	bonus.perspective = 0;
	dna->bonus = &bonus;
	init_func_array(dna);
	init_mlx(dna);
}

static void	init_coords(t_dna *dna)
{
	t_coords	coords;

	coords.x1 = 0;
	coords.y1 = 0;
	coords.x2 = 0;
	coords.y2 = 0;
	coords.h = 0;
	coords.mouse_x = 0;
	coords.mouse_y = 0;
	dna->coords = &coords;
	init_pos(dna);
	init_bonus(dna);
}

static void	init_image(t_dna *dna)
{
	t_image	image;

	image.image_ptr = NULL;
	image.image = NULL;
	image.bpp = 0;
	image.line_length = 0;
	image.endian = 0;
	dna->image = &image;
	init_coords(dna);
}

void		init_dna(int type)
{
	t_dna		dna;

	dna.win = NULL;
	dna.win = NULL;
	dna.image = NULL;
	dna.fractale = type;
	dna.get_core = 0;
	init_image((t_dna *)&dna);
}

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

static void		init_keyhook(t_dna *dna)
{
	dna->f[0] = &pos_gestion;
	dna->f[1] = &iteration_gestion;
	dna->f[2] = &zoom_gestion;
	dna->f[3] = &reset;
	dna->f[4] = &variation_gestion;
	dna->f[5] = &exit_program;
	init_mlx(dna);
}

static void	init_bonus(t_dna *dna)
{
	t_bonus		bonus;

	bonus.iteration_max = 25;
	bonus.win_height = 0;
	bonus.win_width = WIDTH;
	bonus.win_height = HEIGHT;
	bonus.zoom = 100;
	bonus.zoom_add = 100;
	bonus.var = 0.285;
	dna->bonus = &bonus;
	init_keyhook(dna);
}

static void	init_core(t_dna *dna)
{
	t_core		core;

	core.core_one = 0;
	core.core_two = 0;
	dna->core = &core;
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
	init_core(dna);
}

void		init_dna(int type)
{
	t_dna		dna;

	dna.win = NULL;
	dna.win = NULL;
	dna.image = NULL;
	dna.x1 = 0;
	dna.y1 = 0;
	dna.x2 = 0;
	dna.y2 = 0;
	dna.h = 0;
	dna.mouse_x = 0;
	dna.mouse_y = 0;
	dna.fractale = type;
	dna.variation = 0;
	init_pos((t_dna *)&dna);
	init_image((t_dna *)&dna);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:06:08 by gduval            #+#    #+#             */
/*   Updated: 2018/01/17 14:06:08 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		pos_gestion(int keycode, t_dna *dna)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		return (0);
	else
	{
		if (keycode == 123 || keycode == 124)
			dna->coords->x1 = (keycode == 124) ? dna->coords->x1 - 0.1 : \
			dna->coords->x1 + 0.1;
		else if (keycode == 125 || keycode == 126)
			dna->coords->y1 = (keycode == 125) ? dna->coords->y1 - 0.1 : \
			dna->coords->y1 + 0.1;
		return (1);
	}
	return (0);
}

int		perspective_gestion(int keycode, t_dna *dna)
{
	if (keycode != 49)
		return (0);
	else
		dna->bonus->perspective = (dna->bonus->perspective == 0) ? 1 : 0;
	return (0);
}

int		var_gestion(int keycode, t_dna *dna)
{
	if (keycode != 69 && keycode != 78)
		return (0);
	else
	{
		if (dna->bonus->var > -2 && dna->bonus->var < 2)
			dna->bonus->var += (keycode == 69) ? 0.100 : -0.100;
		return (1);
	}
	return (0);
}

int		fractal_gestion(int keycode, t_dna *dna)
{
	if (keycode != 83 && keycode != 84 && keycode != 85 && keycode != 86)
		return (0);
	else
	{
		dna->fractale = keycode % 83;
		return (1);
	}
	return (0);
}

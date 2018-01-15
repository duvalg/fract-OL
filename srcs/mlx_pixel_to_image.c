/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:38:49 by gduval            #+#    #+#             */
/*   Updated: 2018/01/08 10:38:50 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		mlx_pixel_put_to_image(t_dna *dna, int *x, int *y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	long double	img_size;

	img_size = WIDTH * HEIGHT * dna->image->bpp / 8;
	if (*x < 0 || *y < 0 || *y * dna->image->line_length + *x * \
		dna->image->bpp / 8 > img_size || *x >= dna->image->line_length /\
		(dna->image->bpp / 8) || *y >= img_size / dna->image->line_length)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = dna->image->bpp / 8;
	dna->image->image[*y * dna->image->line_length + *x * bit_pix] = color1;
	dna->image->image[*y * dna->image->line_length + *x * bit_pix + 1] = color2;
	dna->image->image[*y * dna->image->line_length + *x * bit_pix + 2] = color3;
}

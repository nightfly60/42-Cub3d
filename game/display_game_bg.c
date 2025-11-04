/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game_bg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:45:50 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 11:58:09 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	top_half_color(int color, t_data *image)
{
	int		y;
	int		x;
	char	*dst;

	y = 0;
	dst = image->addr;
	while (y < SIZE_Y / 2)
	{
		x = 0;
		while (x < SIZE_X)
		{
			*(unsigned int *)dst = color;
			dst += (image->bpp / 8);
			x++;
		}
		y++;
	}
	return (y);
}

static void	down_half_color(int color, t_data *image, int y)
{
	int		x;
	char	*dst;

	dst = image->addr + (y * image->l_line);
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			*(unsigned int *)dst = color;
			dst += (image->bpp / 8);
			x++;
		}
		y++;
	}
}

/*Separer le fond en deux parties : plafond et sol pour les colorer*/
void	display_game_bg(t_cub *cube, t_data *image)
{
	int	y;

	y = top_half_color(cube->textures->ceiling_color, image);
	down_half_color(cube->textures->floor_color, image, y);
}

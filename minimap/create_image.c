/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:41:04 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/16 11:40:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Dessine les (mapcub_size) pixels de chaque ligne a la bonne couleur*/
static void	draw_case(t_cub *cube, t_data *image, int y, int x)
{
	char	*dst;
	char	c;
	int		z;

	z = 0;
	c = cube->map[y / cube->mapcub_size][x];
	while (z < cube->mapcub_size)
	{
		dst = image->addr + (y * image->l_line + (z + x
					* cube->mapcub_size) * (image->bpp / 8));
		if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
			*(unsigned int *)dst = ft_color(173, 117, 32);
		else
			*(unsigned int *)dst = ft_color(91, 78, 62);
		z++;
	}
}

/*Dessine dans l'image la map en 2D*/
void	map_background(t_cub *cube, t_data *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->nb_lines * cube->mapcub_size)
	{
		x = 0;
		while (cube->map[y / cube->mapcub_size][x])
		{
			draw_case(cube, image, y, x);
			x++;
		}
		y++;
	}
}

/*Dessine le player sur la map en 2D*/
void	map_player(t_cub *cube, t_data *image, int ray)
{
	int	x;
	int	y;
	int	x_origin;
	int	y_origin;
	int	dist;

	ray = (ray * SIZE_X) / 1920;
	x_origin = (int)(cube->player->pos_x * cube->mapcub_size);
	y_origin = (int)(cube->player->pos_y * cube->mapcub_size);
	x = (x_origin - ray);
	while (x <= x_origin + ray)
	{
		y = y_origin - ray;
		while (y <= y_origin + ray)
		{
			dist = (x - x_origin) * (x - x_origin) + (y - y_origin) * (y
					- y_origin);
			if (dist < ray * ray)
				put_pixel(image, x, y, ft_color(255, 255, 255));
			y++;
		}
		x++;
	}
}

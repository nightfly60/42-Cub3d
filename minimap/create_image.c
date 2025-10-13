/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:41:04 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/13 12:46:03 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_background(t_cub *cube, t_data *image)
{
	int		x;
	int		y;
	char	*dst;
	char	c;

	y = 0;
	while (y < cube->nb_lines * cube->mapcub_size)
	{
		x = 0;
		while (x < cube->longest_line * cube->mapcub_size)
		{
			dst = image->addr + (y * image->line_length + x
					* (image->bits_per_pixel / 8));
			c = cube->map[y / cube->mapcub_size][x / cube->mapcub_size];
			if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
				*(unsigned int *)dst = ft_color(0, 120, 0);
			else
				*(unsigned int *)dst = ft_color(255, 0, 0);
			x++;
		}
		y++;
	}
}

static void	map_player(t_cub *cube, t_data *image)
{
	t_ply	*ply;

	ply = cube->player;
}

void	*create_image(t_cub *cube)
{
	t_data	image;

	get_mapdata_display(cube);
	image.img = mlx_new_image(cube->mlx, cube->longest_line * cube->mapcub_size,
			cube->nb_lines * cube->mapcub_size);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	map_background(cube, &image);
	return (image.img);
}

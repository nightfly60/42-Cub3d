/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:53:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/03 16:05:01 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_data	*get_image(t_cub *cube, char *pathname)
{
	t_data	*image;

	image = malloc(sizeof(t_data));
	if (!image)
		exit_game(cube);
	image->img = mlx_xpm_file_to_image(cube->mlx, pathname, &image->width,
			&image->height);
	if (!image->img)
	{
		free(image);
		exit_game(cube);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->l_line,
			&image->end);
	return (image);
}

void	init_textures(t_cub *cube)
{
	cube->textures->east = get_image(cube, cube->path_east);
	cube->textures->west = get_image(cube, cube->path_west);
	cube->textures->north = get_image(cube, cube->path_north);
	cube->textures->south = get_image(cube, cube->path_south);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:53:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/17 12:18:42 by aabouyaz         ###   ########.fr       */
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
	cube->textures->ceiling_color = ft_color(0, 100, 200);
	cube->textures->floor_color = ft_color(200, 100, 0);
	cube->textures->east = get_image(cube, cube->path_east);
	free(cube->path_east);
	cube->path_east = NULL;
	cube->textures->west = get_image(cube, cube->path_west);
	free(cube->path_west);
	cube->path_west = NULL;
	cube->textures->north = get_image(cube, cube->path_north);
	free(cube->path_north);
	cube->path_north = NULL;
	cube->textures->south = get_image(cube, cube->path_south);
	free(cube->path_south);
	cube->path_south = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:12:56 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 16:42:41 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display_game(t_cub *cube)
{
	t_data	img_map;
	t_data	img_game;

	img_map.img = NULL;
	img_game.img = NULL;
	cube->img_minimap = img_map.img;
	cube->img_game = img_game.img;
	get_mapdata_display(cube);
	img_map.img = mlx_new_image(cube->mlx, cube->longest_line
			* cube->mapcub_size, cube->nb_lines * cube->mapcub_size);
	img_game.img = mlx_new_image(cube->mlx, SIZE_X, SIZE_Y);
	img_map.addr = mlx_get_data_addr(img_map.img, &img_map.bits_per_pixel,
			&img_map.line_length, &img_map.endian);
	img_game.addr = mlx_get_data_addr(img_game.img, &img_game.bits_per_pixel,
			&img_game.line_length, &img_game.endian);
	map_background(cube, &img_map);
	map_player(cube, &img_map, 10);
	launch_rays(cube, &img_map, &img_game);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window_minimap, img_map.img,
		cube->map_x, cube->map_y);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window_game, img_game.img, 0,
		0);
	mlx_destroy_image(cube->mlx, img_map.img);
	mlx_destroy_image(cube->mlx, img_game.img);
	return (1);
}

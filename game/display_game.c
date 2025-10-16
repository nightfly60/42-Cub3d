/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:12:56 by edurance          #+#    #+#             */
/*   Updated: 2025/10/15 17:55:13 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display_game(t_cub *cube)
{
	t_data	map;
	t_data	game;

	map.img = NULL;
	game.img = NULL;
	cube->img_minimap = map.img;
	cube->img_game = game.img;
	get_mapdata_display(cube);
	map.img = mlx_new_image(cube->mlx, cube->longest_line * cube->mapcub_size,
			cube->nb_lines * cube->mapcub_size);
	game.img = mlx_new_image(cube->mlx, SIZE_X, SIZE_Y);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length,
			&map.endian);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	map_background(cube, &map);
	map_player(cube, &map, 10);
	launch_rays(cube, &map, &game);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window_minimap, map.img,
		cube->map_x, cube->map_y);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window_game, game.img, 0, 0);
	display_fps(cube);
	mlx_destroy_image(cube->mlx, map.img);
	mlx_destroy_image(cube->mlx, game.img);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:12:56 by edurance          #+#    #+#             */
/*   Updated: 2025/11/04 16:56:31 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Fonction principale pour afficher le jeu a chaque frame*/
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
	map.addr = mlx_get_data_addr(map.img, &map.bpp, &map.l_line, &map.end);
	game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.l_line, &game.end);
	map_background(cube, &map);
	map_player(cube, &map, cube->mapcub_size / 2);
	display_game_bg(cube, &game);
	launch_rays(cube, &map, &game);
	display_crosshair(&game);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window_game, game.img, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window_game, map.img, 10, 10);
	display_fps(cube);
	mlx_destroy_image(cube->mlx, map.img);
	mlx_destroy_image(cube->mlx, game.img);
	return (1);
}

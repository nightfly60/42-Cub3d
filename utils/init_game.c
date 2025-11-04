/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:16:34 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 12:11:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_null(t_cub *cube)
{
	cube->player = NULL;
	cube->textures = NULL;
	cube->map = NULL;
	cube->mlx = NULL;
	cube->mlx_window_game = NULL;
	cube->img_minimap = NULL;
	cube->img_game = NULL;
	cube->path_east = NULL;
	cube->path_west = NULL;
	cube->path_north = NULL;
	cube->path_south = NULL;
	cube->map_struct = NULL;
}

static void	create_text_struct(t_cub *cube)
{
	cube->textures = malloc(sizeof(t_textures));
	if (!cube->textures)
		exit_game(cube);
	cube->textures->east = NULL;
	cube->textures->west = NULL;
	cube->textures->south = NULL;
	cube->textures->north = NULL;
}

static void	create_player_struct(t_cub *cube)
{
	cube->player = malloc(sizeof(t_ply));
	if (!cube->player)
		exit_game(cube);
}

/*Fonction principale pour demarrer le jeu*/
void	init_game(t_cub *cube, t_map *map)
{
	init_null(cube);
	cube->map_struct = map;
	cube->minimap_sizex = SIZE_X * 0.25;
	cube->minimap_sizey = SIZE_Y * 0.25;
	cube->fps = ft_itoa(0);
	cube->mlx = mlx_init();
	cube->mlx_window_game = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y, "cub3D");
	create_player_struct(cube);
	create_text_struct(cube);
	link_map(map, cube);
	init_textures(cube);
	init_player_data(cube);
	mlx_hook(cube->mlx_window_game, KeyPress, KeyPressMask, key_hooks, cube);
	mlx_hook(cube->mlx_window_game, MotionNotify, PointerMotionMask,
		mouse_moves, cube);
	mlx_hook(cube->mlx_window_game, 17, 0, close_game, (void *)cube);
}

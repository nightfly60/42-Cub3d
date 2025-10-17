/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:16:34 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/17 13:06:02 by aabouyaz         ###   ########.fr       */
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
	init_textures(cube);
}

static void	create_player_struct(t_cub *cube)
{
	cube->player = malloc(sizeof(t_ply));
	if (!cube->player)
		exit_game(cube);
}

void	init_game(t_cub *cube, char **av)
{
	init_null(cube);
	cube->minimap_sizex = SIZE_X * 0.25;
	cube->minimap_sizey = SIZE_Y * 0.25;
	cube->fps = ft_itoa(0);
	create_map(cube, av[1]);
	cube->mlx = mlx_init();
	cube->mlx_window_game = mlx_new_window(cube->mlx, SIZE_X, SIZE_Y, "cub3D");
	cube->path_east = ft_strdup("./textures/east.xpm");
	cube->path_west = ft_strdup("./textures/west.xpm");
	cube->path_north = ft_strdup("./textures/north.xpm");
	cube->path_south = ft_strdup("./textures/south.xpm");
	create_player_struct(cube);
	create_text_struct(cube);
	init_player_data(cube);
	mlx_hook(cube->mlx_window_game, KeyPress, KeyPressMask, key_hooks, cube);
	mlx_hook(cube->mlx_window_game, MotionNotify, PointerMotionMask,
		mouse_moves, cube);
	mlx_hook(cube->mlx_window_game, 17, 0, close_game, (void *)cube);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:41:41 by edurance          #+#    #+#             */
/*   Updated: 2025/11/03 16:08:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	link_map(t_map *map, t_cub *cube)
{
	cube->map = map->map;
	cube->textures->ceiling_color = map->color_ceiling;
	cube->textures->floor_color = map->color_floor;
	cube->longest_line = map->longest_line;
	cube->nb_lines = map->lines_numbers;
	cube->path_east = map->text_east;
	cube->path_north = map->text_north;
	cube->path_south = map->text_south;
	cube->path_west = map->text_west;
	cube->player->pos_x = map->start_x + 0.5f;
	cube->player->pos_y = map->start_y + 0.5f;
}

int	main(int ac, char **av)
{
	t_cub	*cube;
	t_map	*map;

	if (ac != 2)
		return (1);
	if (SIZE_X > 2000 || SIZE_X < 400 || SIZE_Y > 2000 || SIZE_Y < 400)
		return (1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map_parsing(map, av[1]);
	cube = malloc(sizeof(t_cub));
	if (!cube)
	{
		exit_map(map, "Malloc failed for cube struct");
		return (0);
	}
	init_game(cube, map);
	mlx_loop_hook(cube->mlx, display_game, cube);
	mlx_loop(cube->mlx);
	free(cube);
	return (0);
}

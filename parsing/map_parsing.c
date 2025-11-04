/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:25:25 by edurance          #+#    #+#             */
/*   Updated: 2025/11/03 15:25:48 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_all_textures(t_map *map)
{
	if (!map->text_east)
		exit_map(map, "Texture missing for EAST");
	if (!map->text_north)
		exit_map(map, "Texture missing for NORTH");
	if (!map->text_west)
		exit_map(map, "Texture missing for WEST");
	if (!map->text_south)
		exit_map(map, "Texture missing for SOUTH");
	if (map->color_ceiling == -1)
		exit_map(map, "Color missing for CEILING");
	if (map->color_floor == -1)
		exit_map(map, "Color missing for FLOOR");
}

void	map_parsing(t_map *map, char *filemap)
{
	init_map(map);
	get_filemap(filemap, map);
	get_map(map);
	check_all_char(map);
	get_spawn_pos(map);
	check_map_size(map);
	closed_map(map);
	parse_map_colors(map);
	parse_map_textures(map);
	check_all_textures(map);
	check_lines(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:25:25 by edurance          #+#    #+#             */
/*   Updated: 2025/11/02 16:47:46 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

// void	print_list(void *content)
// {
// 	char	*line;

// 	line = (char *)content;
// 	printf("%s", line);
// }

int	main(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	init_map(map);
	get_filemap("test.cub", map);
	get_map(map);
	parse_map_colors(map);
	parse_map_textures(map);
	check_all_textures(map);
	check_lines(map);
	printf("colors: F = %d et C = %d\n", map->color_floor, map->color_ceiling);
	printf("NO = %s\nSO = %s\nEA = %s\nWE = %s\n", map->text_north,
		map->text_south, map->text_east, map->text_west);
	print_str_table(map->map);
	exit_map(map, NULL);
	return (0);
}

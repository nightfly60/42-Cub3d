/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:08:07 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/03 13:05:07 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->mapfile = NULL;
	map->color_ceiling = -1;
	map->color_floor = -1;
	map->text_north = NULL;
	map->text_south = NULL;
	map->text_east = NULL;
	map->text_west = NULL;
	map->map = NULL;
	map->map_start = NULL;
	map->map_end = NULL;
	map->start_x = -1;
	map->start_y = -1;
}

void	exit_map(t_map *map, char *message)
{
	if (message)
		printf("Error\n%s\n", message);
	ft_lstclear(&map->mapfile, &free);
	free(map->text_north);
	free(map->text_south);
	free(map->text_east);
	free(map->text_west);
	ft_freeall(map->map);
	free(map);
	if (message)
		exit(1);
}

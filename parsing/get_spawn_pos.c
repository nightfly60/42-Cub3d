/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spawn_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:05:24 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/03 13:13:04 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_in(char c, char *dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (c == dict[i])
			return (1);
		i++;
	}
	return (0);
}

void	get_spawn_pos(t_map *map)
{
	char	**table;
	int		i;
	int		j;

	table = map->map;
	i = 0;
	while (table[++i])
	{
		j = 0;
		while (table[i][j])
		{
			if (is_in(table[i][++j], "NSEW"))
			{
				if (map->start_x == -1 && map->start_y == -1)
				{
					map->start_x = j;
					map->start_y = i;
				}
				else
					exit_map(map, "Too many spawns in the map");
			}
		}
	}
	if (map->start_x == -1 || map->start_y == -1)
		exit_map(map, "Spawn missing in the map");
}

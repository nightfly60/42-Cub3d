/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:51:48 by edurance          #+#    #+#             */
/*   Updated: 2025/11/03 14:54:29 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*bas, haut, droite, gauche*/
static void	fill_dirs(int dirs[4][2])
{
	dirs[0][0] = 1;
	dirs[0][1] = 0;
	dirs[1][0] = -1;
	dirs[1][1] = 0;
	dirs[2][0] = 0;
	dirs[2][1] = 1;
	dirs[3][0] = 0;
	dirs[3][1] = -1;
}

static int	flood_fill(char **map, int pos[2])
{
	int			dirs[4][2];
	int			next[2];
	int			i;
	static int	closed = 1;

	fill_dirs(dirs);
	i = -1;
	if (pos[0] < 0 || pos[1] < 0)
		return (0);
	if (map[pos[0]][pos[1]] == '1' || map[pos[0]][pos[1]] == 'X')
		return (1);
	if (map[pos[0]][pos[1]] == '2')
	{
		map[pos[0]][pos[1]] = '3';
		return (0);
	}
	map[pos[0]][pos[1]] = 'X';
	while (++i < 4)
	{
		next[0] = pos[0] + dirs[i][0];
		next[1] = pos[1] + dirs[i][1];
		if (!flood_fill(map, next))
			closed = 0;
	}
	return (closed);
}

void	closed_map(t_map *map)
{
	int		start_pos[2] = {12, 4};
	int		i;
	int		j;
	char	**maptable;

	if (!flood_fill(map->map, start_pos))
		exit_map(map, "The map is not closed: Invalid map");
	i = 0;
	j = 0;
	maptable = map->map;
	while (maptable[i])
	{
		j = 0;
		while (maptable[i][j])
		{
			if (ft_atoi(&maptable[i][j]) == 3)
				exit_map(map, "The map is not closed: Invalid map");
			j++;
		}
		i++;
	}
	ft_freeall(map->map);
	get_map(map);
}

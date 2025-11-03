/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:58:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/03 13:25:16 by aabouyaz         ###   ########.fr       */
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

void	check_all_char(t_map *map)
{
	int		i;
	int		j;
	char	**table;

	table = map->map;
	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			if (!is_in(table[i][j], "012NSEW"))
				exit_map(map, "Invalid character in map");
			j++;
		}
		i++;
	}
	map->lines_numbers = i - 2;
}

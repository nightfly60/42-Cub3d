/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:58:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 12:01:05 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*ft_strchr de Anas*/
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

/*Check si il ya un char invalide dans la map*/
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
	map->lines_numbers = i;
}

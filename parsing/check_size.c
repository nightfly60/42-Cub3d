/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:26:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 12:02:12 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Protection pour le pas avoir une map TROP GROSSE*/
void	check_map_size(t_map *map)
{
	if (map->longest_line > 100)
		exit_map(map, "Map is too large");
	if (map->lines_numbers > 100)
		exit_map(map, "Map is too long");
}

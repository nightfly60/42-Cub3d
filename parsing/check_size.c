/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:26:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/03 13:28:18 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_size(t_map *map)
{
	if (map->longest_line > 200)
		exit_map(map, "Map is too large");
	if (map->lines_numbers > 200)
		exit_map(map, "Map is too long");
}

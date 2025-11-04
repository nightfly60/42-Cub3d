/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:08:07 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 14:53:54 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Mets tout a null pour eviter les pb de free et leaks*/
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

/*Fonction pour exit le programme proprement avec un msg d'erreur*/
void	exit_map(t_map *map, char *message)
{
	if (message)
		printf("Error\n%s\n", message);
	ft_lstclear(&map->mapfile, &free);
	free(map->text_north);
	map->text_north = NULL;
	free(map->text_south);
	map->text_south = NULL;
	free(map->text_east);
	map->text_east = NULL;
	free(map->text_west);
	map->text_west = NULL;
	ft_freeall(map->map);
	free(map);
	if (message)
		exit(1);
}

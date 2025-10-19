/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:25:25 by edurance          #+#    #+#             */
/*   Updated: 2025/10/19 13:27:40 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/include/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

void print_list(void *content)
{
	char *line;

	line = (char *)content;
	printf("%s", line);
}

int get_filemap(char *path, t_map *map)
{
	int fd;
	t_list **filemap;
	char	*line;
	int	i;
	i = 0;

	if (ft_strcmp(&path[ft_strlen(path) - 4], ".cub"))
	{
		printf("Bad file name\n");
		return (1);
	}
	filemap = &map->mapfile;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Map couldnt open\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(filemap, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (0);
}

int main(void)
{
	char **res;
	t_map *map;

	map = malloc(sizeof(t_map));
	map->mapfile = NULL;
	get_filemap("test.cub", map);
	parse_map_colors(map);
	parse_map_textures(map);
	ft_lstiter(map->mapfile, print_list);
	map->color_floor = -1;
	map->color_ceiling = -1;
	printf("colors: F = %d et C = %d\n", map->color_floor, map->color_ceiling);
	printf("NO = %s\nSO =%s\nEA = %s\nWE = %s\n", map->text_north, map->text_south, map->text_east, map->text_west);
	ft_lstclear(&map->mapfile, free);
	free(map);
	return (0);
}

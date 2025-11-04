/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:44:40 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 12:08:22 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	can_open(char *file, t_map *map)
{
	int		fd;
	char	*pathname;

	if (ft_strncmp(file, "./", 2))
	{
		exit_map(map, "Invalid format pour texture file");
		return (0);
	}
	pathname = file;
	if (pathname[ft_strlen(pathname) - 1] == '\n')
		pathname[ft_strlen(pathname) - 1] = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		exit_map(map, "Cannot open texture file");
		return (0);
	}
	close(fd);
	return (1);
}

static int	parse_texture(void *content, char **text_ptr, t_map *map)
{
	char	*str;
	char	**split;

	str = (char *)content;
	split = ft_split(str, ' ');
	if (ft_arrlen(split) != 2)
	{
		ft_freeall(split);
		return (0);
	}
	if (!can_open(split[1], map))
	{
		ft_freeall(split);
		return (0);
	}
	free(*text_ptr);
	*text_ptr = ft_strdup(split[1]);
	ft_freeall(split);
	return (1);
}

/*Recup les textures et verifie qu'elles sont correctes*/
void	parse_map_textures(t_map *map)
{
	t_list	*line;
	int		count;

	count = 0;
	line = map->mapfile;
	while (line && line != map->map_start)
	{
		if (line->content)
		{
			if (!ft_strncmp((char *)line->content, "NO", 2))
				count += parse_texture(line->content, &map->text_north, map);
			else if (!ft_strncmp((char *)line->content, "WE", 2))
				count += parse_texture(line->content, &map->text_west, map);
			else if (!ft_strncmp((char *)line->content, "SO", 2))
				count += parse_texture(line->content, &map->text_south, map);
			else if (!ft_strncmp((char *)line->content, "EA", 2))
				count += parse_texture(line->content, &map->text_east, map);
		}
		line = line->next;
	}
	if (count > 4)
		exit_map(map, "Too many textures in the map");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:44:40 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/10/19 13:22:59 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

static int	can_open(char *file)
{
	int		fd;
	char	*pathname;

	if (ft_strncmp(file, "./", 2))
		return (0);
	pathname = file;
	if (pathname[ft_strlen(pathname) - 1] == '\n')
		pathname[ft_strlen(pathname) - 1] = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static char	*parse_texture(void *content)
{
	char	*str;
	char	**split;
	char	*res;

	str = (char *)content;
	split = ft_split(str, ' ');
	if (ft_arrlen(split) != 2)
	{
		ft_freeall(split);
		return (NULL);
	}
	if (ft_strcmp(split[0], "NO") && ft_strcmp(split[0], "SO")
		&& ft_strcmp(split[0], "WE") && ft_strcmp(split[0], "EA"))
	{
		ft_freeall(split);
		return (NULL);
	}
	if (!can_open(split[1]))
	{
		ft_freeall(split);
		return (NULL);
	}
	res = ft_strdup(split[1]);
	ft_freeall(split);
	return (res);
}

void	parse_map_textures(t_map *map)
{
	t_list	*line;

	line = map->mapfile;
	while (line)
	{
		if (line->content)
		{
			if (!ft_strncmp((char *)line->content, "NO", 2))
				map->text_north = parse_texture(line->content);
			else if (!ft_strncmp((char *)line->content, "WE", 2))
				map->text_west = parse_texture(line->content);
			else if (!ft_strncmp((char *)line->content, "SO", 2))
				map->text_south = parse_texture(line->content);
			else if (!ft_strncmp((char *)line->content, "EA", 2))
				map->text_east = parse_texture(line->content);
		}
		line = line->next;
	}
}

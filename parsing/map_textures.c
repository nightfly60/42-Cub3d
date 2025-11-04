/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:44:40 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/04 15:50:52 by aabouyaz         ###   ########.fr       */
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
	if (ft_strcmp(split[0], "NO") && ft_strcmp(split[0], "SO")
		&& ft_strcmp(split[0], "EA") && ft_strcmp(split[0], "WE"))
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

static char	*str_without_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (&s[i]);
}

/*Recup les textures et verifie qu'elles sont correctes*/
void	parse_map_textures(t_map *map)
{
	t_list	*line;
	int		count;
	char	*whitout_space;

	count = 0;
	line = map->mapfile;
	while (line && line != map->map_start)
	{
		if (line->content)
		{
			whitout_space = str_without_space((char *)line->content);
			if (!ft_strncmp(whitout_space, "NO", 2))
				count += parse_texture(line->content, &map->text_north, map);
			else if (!ft_strncmp(whitout_space, "WE", 2))
				count += parse_texture(line->content, &map->text_west, map);
			else if (!ft_strncmp(whitout_space, "SO", 2))
				count += parse_texture(line->content, &map->text_south, map);
			else if (!ft_strncmp(whitout_space, "EA", 2))
				count += parse_texture(line->content, &map->text_east, map);
		}
		line = line->next;
	}
	if (count > 4)
		exit_map(map, "Too many textures in the map");
}

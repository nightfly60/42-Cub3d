/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:21:24 by edurance          #+#    #+#             */
/*   Updated: 2025/11/04 16:15:19 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) <= 1)
		return (0);
	while (line[i] && ft_strchr("10 \nEWNS", line[i]))
		i++;
	if (!line[i])
		return (1);
	return (0);
}

static char	*malloc_line(char *line, int len, t_map *map)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (len + 3));
	if (!res)
		exit_map(map, "Malloc failed");
	res[0] = '2';
	while (line && line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
			res[i + 1] = line[i];
		else
			res[i + 1] = '1';
		i++;
	}
	while (i < len - 1)
	{
		res[i + 1] = '2';
		i++;
	}
	res[i + 1] = '2';
	res[i + 2] = 0;
	return (res);
}

static int	get_longest_line(t_map *map)
{
	t_list			*current_line;
	unsigned long	longest_line;

	current_line = map->map_start;
	longest_line = ft_strlen((char *)current_line->content);
	while (current_line && current_line->content)
	{
		if (longest_line < ft_strlen((char *)current_line->content))
			longest_line = ft_strlen((char *)current_line->content);
		current_line = current_line->next;
	}
	map->longest_line = (int)longest_line;
	return ((int)longest_line);
}

static void	copy_map(t_map *map, int size)
{
	int		i;
	char	**res;
	t_list	*current_line;
	int		longest_line;

	if (!map->map_start)
		exit_map(map, "Can I get a map please \?");
	i = 1;
	longest_line = get_longest_line(map);
	current_line = map->map_start;
	current_line = map->map_start;
	res = ft_calloc((size + 3), sizeof(char *));
	if (!res)
		return ;
	res[0] = malloc_line(NULL, longest_line, map);
	while (current_line && i < size + 1)
	{
		res[i++] = malloc_line((char *)(current_line)->content, longest_line,
				map);
		current_line = (current_line)->next;
	}
	res[i] = malloc_line(NULL, longest_line, map);
	res[i + 1] = NULL;
	map->map = res;
	map->map_end = current_line;
}

/*Sauve la map dans un char ** */
void	get_map(t_map *map)
{
	t_list	*filemap;
	int		i;

	i = 0;
	filemap = map->mapfile;
	while (filemap)
	{
		if (!valid_line((char *)filemap->content))
			filemap = filemap->next;
		else
			break ;
	}
	map->map_start = filemap;
	while (filemap)
	{
		if (ft_strlen((char *)filemap->content) <= 1)
			break ;
		i++;
		filemap = filemap->next;
	}
	copy_map(map, i);
	if (!map->map)
		exit_map(map, "Map Invalid");
}

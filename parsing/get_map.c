/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:21:24 by edurance          #+#    #+#             */
/*   Updated: 2025/11/02 17:16:48 by aabouyaz         ###   ########.fr       */
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

static char	*malloc_line(char *line, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	while (i < len - 1)
	{
		res[i] = '2';
		i++;
	}
	res[i] = 0;
	return (res);
}

static void	copy_map(t_map *map, int size)
{
	int		i;
	char	**res;
	t_list	*current_line;
	int		longest_line;

	i = 0;
	current_line = map->map_start;
	longest_line = ft_strlen((char *)current_line->content);
	while (current_line && current_line->content)
	{
		if (longest_line < ft_strlen((char *)current_line->content))
			longest_line = ft_strlen((char *)current_line->content);
		current_line = current_line->next;
	}
	current_line = map->map_start;
	res = malloc(sizeof(char *) * (size + 1));
	while (current_line && i < size)
	{
		res[i] = malloc_line((char *)(current_line)->content, longest_line);
		i++;
		current_line = (current_line)->next;
	}
	map->map_end = current_line;
	res[i] = NULL;
	map->map = res;
}

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
}

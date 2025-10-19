/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:21:24 by edurance          #+#    #+#             */
/*   Updated: 2025/10/19 15:34:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) <= 1)
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && (line[i] == '1' || line[i] == '\n'))
		i++;
	if (!line[i])
		return (1);
	if (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (!line[i] || line[i] == '\n')
			return (1);
	}
	return (0);
}

static char	**copy_map(t_list *map_start, int size)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char *) * (size + 1));
	while (map_start && i < size)
	{
		res[i] = ft_strdup((char *)(map_start)->content);
		i++;
		map_start = (map_start)->next;
	}
	res[i] = NULL;
	return (res);
}

char	**get_map(t_map *map)
{
	t_list	**filemap;
	t_list	*map_start;
	char	**res;
	int		i;

	i = 0;
	filemap = &map->mapfile;
	while ((*filemap))
	{
		if (!valid_line((char *)(*filemap)->content))
			*filemap = (*filemap)->next;
		else
			break ;
	}
	map_start = *filemap;
	while ((*filemap))
	{
		if (ft_strlen((char *)(*filemap)->content) <= 1)
			break ;
		i++;
		*filemap = (*filemap)->next;
	}
	res = copy_map(map_start, i);
	return (res);
}

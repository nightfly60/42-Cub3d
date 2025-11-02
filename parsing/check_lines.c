/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:52:45 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/02 16:06:27 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_line(char *s)
{
	int	i;

	i = 0;
	if (!ft_strncmp(s, "NO", 2) || !ft_strncmp(s, "SO", 2))
		return (1);
	else if (!ft_strncmp(s, "EA", 2) || !ft_strncmp(s, "WE", 2))
		return (1);
	else if (!ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1))
		return (1);
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_lines(t_map *map)
{
	t_list	*current;
	int		i;

	current = map->mapfile;
	while (current && current->content && current != map->map_start)
	{
		if (!valid_line((char *)current->content))
			exit_map(map, "Invalid line in file");
		current = current->next;
	}
	current = map->map_end;
	while (current && current->content)
	{
		i = 0;
		while (((char *)current->content)[i])
		{
			if (!ft_isspace(((char *)current->content)[i]))
				exit_map(map, "Invalid line in file");
			i++;
		}
		current = current->next;
	}
}

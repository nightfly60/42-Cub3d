/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:52:45 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/11/02 16:46:38 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_line(char *s)
{
	if (!ft_strncmp(s, "NO", 2) || !ft_strncmp(s, "SO", 2))
		return (1);
	else if (!ft_strncmp(s, "EA", 2) || !ft_strncmp(s, "WE", 2))
		return (1);
	else if (!ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1))
		return (1);
	else if (!strcmp(s, "\n"))
		return (1);
	return (0);
}

void	check_lines(t_map *map)
{
	t_list	*current;

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
		if (ft_strcmp((char *)current->content, "\n"))
			exit_map(map, "Invalid line in file");
		current = current->next;
	}
}

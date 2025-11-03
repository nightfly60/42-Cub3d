/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:19:46 by edurance          #+#    #+#             */
/*   Updated: 2025/11/02 17:16:11 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_filemap(char *path, t_map *map)
{
	int		fd;
	t_list	**filemap;
	char	*line;
	int		i;

	i = 0;
	if (ft_strcmp(&path[ft_strlen(path) - 4], ".cub"))
		exit_map(map, "Bad file name");
	filemap = &map->mapfile;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_map(map, "Map couldn't open");
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(filemap, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (0);
}

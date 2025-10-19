/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:25:25 by edurance          #+#    #+#             */
/*   Updated: 2025/10/19 11:38:25 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/include/libft.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list t_list;

typedef struct s_map
{
	t_list	*mapfile;
}			t_map;

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
	ft_lstiter(map->mapfile, print_list);
	ft_lstclear(&map->mapfile, free);
	free(map);
	return (0);
}

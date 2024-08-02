/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:58:31 by skanin            #+#    #+#             */
/*   Updated: 2024/07/31 14:42:11 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_file.h"
#include "ft_validator.h"

t_map	*load_map(int fd)
{
	t_file	*file;
	t_map	*map;

	file = build_file(fd);
	file->buffer = get_content(file);
	map = (t_map *) malloc(sizeof(t_map));
	map->file = file;
	map->h_length = 0;
	map->height = 0;
	map->width = 0;
	if ((!map_header(map, (unsigned char *) file -> buffer)) || \
	!(valid_content(map) && content_match(map)))
	{
		free(map->file->buffer);
		free(map->file);
		free(map);
		return (NULL);
	}
	return (map);
}

t_tool	build_tool(void)
{
	t_tool	tools;
	int		index;

	tools.i = 0;
	tools.j = 0;
	tools.k = 0;
	tools.x = 0;
	tools.y = 0;
	tools.index = 0;
	tools.length = 0;
	index = 0;
	while (index < 256)
		tools.ascii[index++] = 0;
	return (tools);
}

int	map_header(t_map *map, unsigned char *map_content)
{
	t_tool	tools;

	tools = build_tool();
	while (map_content[tools.i] >= '0' && map_content[tools.i] <= '9')
		map->height = (map->height * 10) + (map_content[tools.i++] - '0');
	while ((map_content[tools.i] >= ' ' && map_content[tools.i] <= '~'))
	{
		if (tools.ascii[map_content[tools.i]] >= 1 || tools.length > 3)
			return (0);
		else if (tools.length == 0)
			map->empty = map_content[tools.i];
		else if (tools.length == 1)
			map->obstacle = map_content[tools.i];
		else if (tools.length == 2)
			map->fill = map_content[tools.i];
		tools.length++;
		tools.ascii[map_content[tools.i]]++;
		tools.i++;
	}
	if (map->height <= 0 || tools.length != 3 || map->height > 65535)
		return (0);
	return (1);
}

int	**build_matrix(t_map *map)
{
	int		width;
	int		**matrix;
	t_tool	tools;

	width = map->width - 1;
	tools = build_tool();
	matrix = (int **) malloc(map->height * sizeof(int *));
	while (tools.length < map->height)
	{
		matrix[tools.length] = (int *) malloc(width * sizeof(int));
		while (tools.i < width)
		{
			matrix[tools.length][tools.i] = 0;
			tools.i++;
		}
		tools.length++;
	}
	return (matrix);
}

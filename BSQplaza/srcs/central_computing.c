/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_computing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:54:13 by skanin            #+#    #+#             */
/*   Updated: 2024/08/02 00:17:32 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "central.h"
#include <stdio.h>

void	print_summary(t_map *map, int max_length)
{
	t_tool	tools;

	tools = build_tool();
	tools.length = max_length * max_length;
	//while (tools.i < map->height)
	//{
	//	tools.j = 0;
	//	while (tools.j < map-> width - 1)
	//	{
	//		if (map->matrix[tools.i][tools.j] == 0)
	//			write(1, &map->obstacle, 1);
	//		else if (map->matrix[tools.i][tools.j]
	//		== max_length && tools.k < tools.length)
	//		{
	//			write(1, &map->fill, 1);
	//			tools.k += 1;
	//		}
	//		else
	//			write(1, &map->empty, 1);
	//		tools.j++;
	//	}
	//	write(1, "\n", 1);
	//	tools.i++;
	//}
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width-1; j++)
		{
			printf("%d", map->matrix[i][j]);
		}
		printf("\n");
	}
}

void	build_square(t_map *map, int x, int y, int size)
{
	t_tool	tools;

	tools = build_tool();
	tools.i = size - 1;
	while (0 <= tools.i)
	{
		tools.j = size - 1;
		while (0 <= tools.j)
		{
			map->matrix[y - tools.i][x - tools.j] = size;
			tools.j--;
		}
		tools.i--;
	}
	print_summary(map, size);
}

void	compute_square(t_map *map)
{
	t_tool	tools;

	tools = build_tool();
	tools.i = 0;
	while (tools.i < map->height)
	{
		tools.j = 0;
		while (tools.j < map->width - 1)
		{
			if (map->matrix[tools.i][tools.j] == 1)
				map->matrix[tools.i][tools.j] += \
				ft_min(map->matrix[tools.i - 1][tools.j - 1], \
				ft_min(map->matrix[tools.i - 1][tools.j], \
				map->matrix[tools.i][tools.j - 1]));
			if (map->matrix[tools.i][tools.j] > tools.length)
			{
				tools.length = map->matrix[tools.i][tools.j];
				tools.x = tools.j;
				tools.y = tools.i;
			}
			tools.j++;
		}
		tools.i++;
	}
	build_square(map, tools.x, tools.y, tools.length);
}

int	**fill_matrix(t_map *map)
{
	t_tool	tools;
	int		width;

	tools = build_tool();
	width = map->width - 1;
	tools.k = map->h_length + 1;
	while (tools.i < map->height)
	{
		tools.j = 0;
		while (tools.j < width)
		{
			if (map->file->buffer[tools.k] == '\n')
				tools.k++;
			if (map->file->buffer[tools.k] == map->empty)
				map->matrix[tools.i][tools.j] = 1;
			else if (map->file->buffer[tools.k] == map->obstacle)
				map->matrix[tools.i][tools.j] = 0;
			tools.k++;
			tools.j++;
		}
		tools.i++;
	}

	return (map->matrix);
}

int	search_square(int fd)
{
	t_map	*map;
	int		index;

	map = load_map(fd);
	if (map == NULL)
		return (0);
	map->matrix = build_matrix(map);
	map->matrix = fill_matrix(map);
	compute_square(map);
	index = 0;
	while (index < map->height)
		free(map->matrix[index++]);
	free(map->matrix);
	free(map->file->buffer);
	free(map->file);
	free(map);
	return (1);
}

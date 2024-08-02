/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:15:07 by skanin            #+#    #+#             */
/*   Updated: 2024/07/31 15:43:36 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validator.h"
#include "ft_map.h"

int	content_match(t_map *map)
{
	int	index;
	int	error;

	index = map->h_length + 1;
	error = 0;
	while (map->file->buffer[index] != '\0')
	{
		if (map->file->buffer[index] != '\n' && map->file->buffer[index] != \
		map->empty && map->file->buffer[index] != \
		map->obstacle)
		{
			error++;
		}
		index++;
	}
	if (error > 0)
		return (0);
	return (1);
}

int	valid_content(t_map *map)
{
	t_tool	tools;

	tools = build_tool();
	while (map->file->buffer[tools.index] != '\0')
	{
		if (map->file->buffer[tools.index] == '\n')
		{
			tools.i++;
			if (tools.length > map->width || tools.length < map->width)
			{
				map->width = tools.length;
				tools.k++;
			}
			tools.length = 0;
		}
		if (tools.i >= 1)
			tools.length++;
		else if (tools.i == 0)
			map->h_length++;
		tools.index++;
	}
	if (tools.k > 1 || tools.i > (map->height + 1) || \
			tools.i < (map->height + 1))
		return (0);
	return (1);
}

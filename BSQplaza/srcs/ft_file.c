/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:05:59 by skanin            #+#    #+#             */
/*   Updated: 2024/07/31 14:31:49 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_file.h"
#include <stdio.h>

t_file	*build_file(int fd)
{
	t_file	*file;
	int		index;

	index = 0;
	file = (t_file *) malloc(sizeof(t_file));
	file->fd = fd;
	file->max_bytes = BYTES;
	file->buffer = (char *) malloc(BYTES + 1);
	file->used = 0;
	while (index < BYTES + 1)
		file->buffer[index++] = 0;
	return (file);
}

static void	update_memory(t_file *file)
{
	char	*temp;
	int		index;

	file->max_bytes *= 2;
	temp = (char *) malloc(file->max_bytes + 1);
	index = 0;
	while (index < file->max_bytes)
		temp[index++] = 0;
	temp = ft_strncpy(temp, file->buffer, file->max_bytes + 1);
	free(file->buffer);
	file->buffer = temp;
}

char	*get_content(t_file *file)
{
	ssize_t	mem_read;

	while (1)
	{
		if (file->used + BYTES > file->max_bytes)
			update_memory(file);
		mem_read = read(file->fd, file->buffer + file->used, BYTES);
		if (mem_read == 0)
			break ;
		file->used += mem_read;
	}
	close(file->fd);
	return (file->buffer);
}

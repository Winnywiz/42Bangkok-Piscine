/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:15:09 by skanin            #+#    #+#             */
/*   Updated: 2024/07/27 18:28:02 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BYTES 512

typedef struct FILE
{
	int		fd;
	char	*buffer;
	ssize_t	buffer_bytes;
	ssize_t	read_bytes;
	ssize_t	used_bytes;
}	t_file;

t_file	ft_build_file(t_file txt, char *path);
t_file	ft_update_file(t_file txt);
void	ft_usage(ssize_t bytes);
ssize_t	ft_read_file(char *path, char **buffer);
#endif

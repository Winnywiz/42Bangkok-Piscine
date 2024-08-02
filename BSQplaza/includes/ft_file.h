/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <winnyscge@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:11:36 by skanin            #+#    #+#             */
/*   Updated: 2024/07/31 12:28:09 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# define BYTES 16
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_file
{
	int		fd;
	char	*buffer;
	ssize_t	max_bytes;
	ssize_t	used;
}	t_file;

t_file	*build_file(int fd);
char	*get_content(t_file *file);
#endif

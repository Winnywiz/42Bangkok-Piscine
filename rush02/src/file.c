/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:23:41 by skanin            #+#    #+#             */
/*   Updated: 2024/07/27 22:31:29 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_usage(ssize_t bytes)
{
	write(1, "Memory used: ", 13);
	ft_putnbr((int) bytes);
	write(1, " Bytes\n", 7);
}

void	ft_print_summary(char *buffer, ssize_t bytes)
{
	ft_putstr(buffer);
	ft_usage(bytes);
	free(buffer);
}

t_file	ft_build_file(t_file txt, char *path)
{
	txt.fd = open(path, O_RDONLY);
	txt.buffer_bytes = BYTES;
	txt.read_bytes = 0;
	txt.used_bytes = 0;
	txt.buffer = (char *) malloc(txt.buffer_bytes);
	if (txt.buffer == NULL)
	{
		txt.fd = -1;
	}
	return (txt);
}

t_file	ft_update_file(t_file txt)
{
	char	*temp;

	txt.buffer_bytes *= 2;
	temp = (char *) malloc(txt.buffer_bytes);
	if (temp == NULL)
	{
		free(txt.buffer);
		close(txt.fd);
		txt.fd = -1;
		return (txt);
	}
	temp = ft_strncpy(temp, txt.buffer, (unsigned int) txt.used_bytes);
	free(txt.buffer);
	txt.buffer = temp;
	return (txt);
}

ssize_t	ft_read_file(char *path, char **buffer)
{
	t_file	txt;

	txt = ft_build_file(txt, path);
	while (1)
	{
		txt.read_bytes = read(txt.fd, txt.buffer + txt.used_bytes, BYTES);
		if (txt.read_bytes == 0 || txt.fd == -1)
			break ;
		txt.used_bytes += txt.read_bytes;
		if (txt.read_bytes + BYTES > txt.buffer_bytes)
		{
			txt = ft_update_file(txt);
		}
	}
	if (txt.fd == -1)
		return (-1);
	*buffer = txt.buffer;
	close(txt.fd);
	return (txt.used_bytes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:52:20 by skhaziev          #+#    #+#             */
/*   Updated: 2024/07/28 22:14:34 by skhaziev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	ft_space(int fd, char c)
{
	while (c == ' ')
	{
		if (!(read(fd, &c, 1)))
			return (0);
	}
	return (c);
}

char	ft_while_spaces(int fd, char c)
{
	if (c == ':')
	{
		if (!(read(fd, &c, 1)))
			return (0);
		return (ft_space(fd, c));
	}
	else if (c == ' ')
	{
		while (c != ':' && c != 0)
		{
			if (!(read(fd, &c, 1)))
				return (0);
		}
		if (!(read(fd, &c, 1)))
			return (0);
		return (ft_space(fd, c));
	}
	return (0);
}

char	ft_go_to_digit(int fd, char *digit)
{
	int		i;
	char	c;
	int		first;

	i = 0;
	first = 1;
	while (read(fd, &c, 1))
	{
		while (c == digit[i] && first)
		{
			if (read(fd, &c, 1))
			{
				i++;
				if ((c == ':' || c == ' ') && digit[i] == '\0')
					return (ft_while_spaces(fd, c));
			}
			else
				return (0);
		}
		first = 0;
		i = 0;
		if (c == '\n')
			first = 1;
	}
	return (0);
}

int	ft_output(char *digit, char *dictionary_file)
{
	char	c;
	int		fd;

	fd = open(dictionary_file, O_RDONLY);
	if (fd <= 0)
		return (1);
	c = ft_go_to_digit(fd, digit);
	if (c)
	{
		while (c != '\n')
		{
			if (c >= 32 && c <= 126)
				write(1, &c, 1);
			read(fd, &c, 1);
		}
		if (close(fd) < 0)
			return (1);
		return (0);
	}
	return (1);
}

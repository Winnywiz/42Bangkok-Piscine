/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:28:17 by skanin            #+#    #+#             */
/*   Updated: 2024/07/27 22:39:06 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#define DEFAULT_PATH "numbers.dict"

void	ft_putstr(char *str);

void	ft_print_summary(char *buffer, ssize_t bytes);

int	main(int size, char *params[])
{
	char	*buffer;
	ssize_t	bytes;

	if (size == 3)
	{
		bytes = ft_read_file(params[2], &buffer);
		ft_putstr(buffer);
		ft_usage(bytes);
		free(buffer);
	}
	else if (size == 2)
	{
	}
	else if (size == 1)
	{
		bytes = ft_read_file(DEFAULT_PATH, &buffer);
		ft_print_summary(buffer, bytes);
	}
	return (0);
}

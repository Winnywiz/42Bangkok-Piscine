/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:16:56 by skanin            #+#    #+#             */
/*   Updated: 2024/07/28 21:45:06 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	main(int size, char *params[])
{
	int	index;

	index = 1;
	while (index < size)
	{
		write(1, params[index], ft_strlen(params[index]));
		write(1, "\n", 1);
		index++;
	}
	return (0);
}

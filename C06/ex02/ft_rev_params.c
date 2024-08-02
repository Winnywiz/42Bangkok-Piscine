/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:57:32 by skanin            #+#    #+#             */
/*   Updated: 2024/07/28 21:45:23 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

int	main(int size, char *params[])
{
	size -= 1;
	while (size > 0)
	{
		write(1, params[size], ft_strlen(params[size]));
		write(1, "\n", 1);
		size--;
	}
}

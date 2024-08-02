/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:08:46 by skanin            #+#    #+#             */
/*   Updated: 2024/07/28 23:41:40 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	length;

	length = 0;
	while (src[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*new_ptr;

	new_ptr = (char *) malloc(ft_strlen(src) + 1);
	index = 0;
	while (src[index] != '\0')
	{
		new_ptr[index] = src[index];
		index++;
	}
	new_ptr[index] = '\0';
	return (new_ptr);
}

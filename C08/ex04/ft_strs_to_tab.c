/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:54:07 by skanin            #+#    #+#             */
/*   Updated: 2024/08/01 15:10:26 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*_str;

	index = 0;
	_str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (_str == NULL)
		return (NULL);
	while (index < ac)
	{
		_str[index].size = ft_strlen(av[index]);
		_str[index].str = av[index];
		_str[index].copy = ft_strdup(av[index]);
		index++;
	}
	_str[index].str = 0;
	_str[index].size = 0;
	_str[index].copy = 0;
	return (_str);
}

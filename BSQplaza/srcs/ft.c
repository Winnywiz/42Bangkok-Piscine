/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <sippakorn.kan@student.42bangkok.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:00:21 by skanin            #+#    #+#             */
/*   Updated: 2024/07/31 06:39:54 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (*str != '\0')
	{
		a++;
		str++;
	}
	return (a);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*process;

	process = dest;
	while (*src != '\0' && n > 0)
	{
		*process++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*process++ = '\0';
		n--;
	}
	return (dest);
}

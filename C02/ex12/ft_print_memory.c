/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:11:52 by skanin            #+#    #+#             */
/*   Updated: 2024/07/18 18:21:17 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*prc;
	int				index;
	char			*hex;

	size++;
	index = size;
	hex = "0123456789abcdef";
	prc = (unsigned char *) addr;
	index = 0;
	while (prc[index] != '\0')
	{
		ft_putchar(hex[prc[index] / 16]);
		ft_putchar(hex[prc[index] % 16]);
		if ((index + 1) % 2 == 0)
		{
			ft_putchar(' ');
		}
		index++;
	}
	return (addr);
}

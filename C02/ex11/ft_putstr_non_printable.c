/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:53:08 by skanin            #+#    #+#             */
/*   Updated: 2024/07/18 17:57:43 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*prc;
	unsigned char	d;
	char			*hex;

	hex = "0123456789abcdef";
	prc = (unsigned char *) str;
	while (*prc != '\0')
	{
		if (*prc >= ' ' && *prc <= '~')
		{
			ft_putchar(*prc);
		}
		else
		{
			ft_putchar('\\');
			d = *prc / 16;
			ft_putchar(hex[d]);
			d = *prc % 16;
			ft_putchar(hex[d]);
		}
		prc++;
	}
}

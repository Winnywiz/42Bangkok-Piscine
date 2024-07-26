/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:36:21 by skanin            #+#    #+#             */
/*   Updated: 2024/07/22 14:47:38 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(unsigned char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

int	base_char_check(unsigned char *base)
{
	int	ascii[256];
	int	index;

	index = 0;
	while (index < 256)
	{
		ascii[index] = 0;
		index++;
	}
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || ascii[*base] > 1)
			return (0);
		ascii[*base]++;
		base++;
	}
	return (1);
}

int	base_validator(unsigned char *base)
{
	int	base_length;

	base_length = ft_strlen(base);
	if (base_length == 10 || base_length == 2 || \
	base_length == 16 || base_length == 8)
	{
		if (base_char_check(base))
			return (1);
	}
	return (0);
}

void	ft_putbase(long nbr, unsigned char *base, int base_length)
{
	if (nbr >= base_length)
		ft_putbase(nbr / base_length, base, base_length);
	write(1, &base[nbr % base_length], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned char	*u_base;
	long			l_nbr;

	l_nbr = (long) nbr;
	u_base = (unsigned char *) base;
	if (base_validator(u_base))
	{
		if (l_nbr < 0)
		{
			l_nbr = -l_nbr;
			write(1, "-", 1);
		}
		ft_putbase(l_nbr, u_base, ft_strlen(u_base));
	}
}
/*
int	main(void)
{
	int		nbr;
	char	*base;

	nbr = -2147483648;
	base = "01";
	ft_putnbr_base(nbr, base);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:00 by skanin            #+#    #+#             */
/*   Updated: 2024/07/25 16:34:18 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
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

int	extended_validator(unsigned char *str, int ascii[256])
{
	unsigned char	*og_str;

	og_str = str;
	while (*og_str == ' ')
	{
		og_str++;
		str++;
	}
	while (*og_str != '\0')
	{
		if (*og_str == ' ')
			return (0);
		else if (ascii[*og_str] == 0)
			return (0);
		og_str++;
	}
	while (*str != '\0')
	{
		if (ascii[*str] == 0)
			return (0);
		str++;
	}
	return (1);
}

int	validator(char *str, char *base, int base_length)
{
	int				index;
	int				ascii[256];
	unsigned char	*u_base;

	index = 0;
	u_base = (unsigned char *) base;
	while (index < 256)
	{
		ascii[index] = 0;
		index++;
	}
	if (base_length != 2 && base_length != 8 && \
	base_length != 10 && base_length != 16)
		return (0);
	while (*u_base != '\0')
	{
		if (*u_base == '+' || *u_base == '-' || ascii[*u_base] > 1)
			return (0);
		ascii[*u_base]++;
		u_base++;
	}
	if (!extended_validator((unsigned char *)str, ascii))
		return (0);
	return (1);
}

int	ft_find_index(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int	max;
	int	result;
	int	multiplier;
	int	base_length;

	max = ft_strlen(str);
	result = 0;
	multiplier = 1;
	base_length = ft_strlen(base);
	if (!validator(str, base, base_length))
	{
		return (0);
	}
	while (max > 0)
	{
		result += ft_find_index(str[max - 1], base) * multiplier;
		multiplier *= base_length;
		max--;
	}
	return (result);
}

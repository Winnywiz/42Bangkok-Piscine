/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:24:10 by aazanov           #+#    #+#             */
/*   Updated: 2024/07/28 19:08:53 by aazanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h"

int	len_num(char *num_str)
{
	int	i;

	i = 0;
	while (num_str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ten_str(int x)
{
	int		i;
	char	*arr;

	i = 1;
	if (x == 0)
		return (NULL);
	arr = (char *)(malloc(sizeof(char) * x + 1));
	arr[0] = '1';
	while (i != x + 1)
	{
		arr[i] = '0';
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	ten_pow(int x)
{
	int		ten;

	ten = 1;
	if (x == 0)
	{
		return (0);
	}
	while (x > 0)
	{
		ten *= 10;
		x--;
	}
	return (ten);
}

int	lenght_int(int num)
{
	int	i;
	int	x;

	i = 0;
	x = num;
	while (x / 10 != 0)
	{
		i++;
		x /= 10;
	}
	return (i + 1);
}

char	*rever(int nb)
{
	int		lenght_n;
	int		i;
	char	*vf;
	char	*res;

	i = 0;
	lenght_n = lenght_int(nb);
	vf = (char *)(malloc(sizeof(char) * lenght_n));
	res = (char *)(malloc(sizeof(char) * lenght_n));
	while (i != lenght_n)
	{
		vf[i] = (nb % 10) + '0';
		i++;
		nb /= 10;
	}
	vf[i] = '\0';
	i = 0;
	while (vf[i] != '\0')
	{
		lenght_n--;
		res[i] = vf[lenght_n];
		i++;
	}
	free(vf);
	return (res);
}

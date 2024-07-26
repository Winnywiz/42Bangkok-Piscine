/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:48:11 by skanin            #+#    #+#             */
/*   Updated: 2024/07/11 08:53:54 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_int_to_char(int a, int b)
{
	char	c_a[2];
	char	c_b[2];

	c_a[0] = (a / 10) + 48;
	c_a[1] = (a % 10) + 48;
	c_b[0] = (b / 10) + 48;
	c_b[1] = (b % 10) + 48;
	write(1, c_a, 2);
	write(1, " ", 1);
	write(1, c_b, 2);
	if (!(a == 98 && b == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	chunk_a;
	int	chunk_b;

	chunk_a = 0;
	while (chunk_a <= 98)
	{
		chunk_b = chunk_a + 1;
		while (chunk_b <= 99)
		{
			ft_int_to_char(chunk_a, chunk_b);
			chunk_b++;
		}
		chunk_a++;
	}
}

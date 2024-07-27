/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:23 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/21 09:35:32 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_sol(int board[6][6])
{
	int	i;
	int	n;

	n = 1;
	while (n < 5)
	{
		i = 1;
		while (i < 5)
		{
			ft_putchar(board[n][i] + '0');
			if (i != 4)
			{
				ft_putchar(' ');
			}
			i++;
		}
		n++;
		ft_putchar('\n');
	}
}

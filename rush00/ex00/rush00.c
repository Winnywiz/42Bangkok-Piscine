/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:01:25 by ctharawi          #+#    #+#             */
/*   Updated: 2024/07/13 13:02:49 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	header_footer(int x_cr, int x)
{
	if (x_cr == 1 || x_cr == x)
	{
		ft_putchar('o');
	}
	else
	{
		ft_putchar('-');
	}
}

void	body(int x_cr, int x)
{
	if (x_cr == 1 || x_cr == x)
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	create(int y_cr, int y, int x_cr, int x)
{
	if (y_cr == 1 || y_cr == y)
	{
		header_footer(x_cr, x);
	}
	else if (y_cr != y)
	{
		body(x_cr, x);
	}
}

void	rush(int x, int y)
{
	int	x_cr;
	int	y_cr;

	if (x <= 0)
	{
		x = -x;
	}
	if (y <= 0)
	{
		y = -y;
	}
	x_cr = 1;
	y_cr = 1;
	while (y_cr < y + 1)
	{
		x_cr = 1;
		while (x_cr < x +1)
		{
			create(y_cr, y, x_cr, x);
			++x_cr;
		}
		write(1, "\n", 1);
		++y_cr;
	}
}

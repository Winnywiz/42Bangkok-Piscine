/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:52:28 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/21 09:27:20 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_col_up(int board[6][6])
{
	int	i;
	int	n;
	int	tmp;
	int	c;

	n = 1;
	while (n <= 4)
	{
		i = 1;
		tmp = 0;
		c = 0;
		while (i <= 4)
		{
			if (tmp < board[i][n])
			{
				tmp = board[i][n];
				c++;
			}
			i++;
		}
		if (c != board[0][n])
			return (0);
		n++;
	}
	return (1);
}

int	ft_col_down(int board[6][6])
{
	int	i;
	int	n;
	int	tmp;
	int	c;

	n = 1;
	while (n <= 4)
	{
		i = 4;
		tmp = 0;
		c = 0;
		while (i >= 1)
		{
			if (tmp < board[i][n])
			{
				tmp = board[i][n];
				c++;
			}
			i--;
		}
		if (c != board[5][n])
			return (0);
		n++;
	}
	return (1);
}

int	ft_row_left(int board[6][6])
{
	int	i;
	int	n;
	int	tmp;
	int	c;

	i = 1;
	while (i <= 4)
	{
		n = 1;
		tmp = 0;
		c = 0;
		while (n <= 4)
		{
			if (tmp < board[i][n])
			{
				tmp = board[i][n];
				c++;
			}
			n++;
		}
		if (c != board[i][0])
			return (0);
		i++;
	}
	return (1);
}

int	ft_row_right(int board[6][6])
{
	int	i;
	int	n;
	int	tmp;
	int	c;

	i = 1;
	while (i <= 4)
	{
		n = 4;
		tmp = 0;
		c = 0;
		while (n >= 1)
		{
			if (tmp < board[i][n])
			{
				tmp = board[i][n];
				c++;
			}
			n--;
		}
		if (c != board[i][5])
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid(int board[6][6])
{
	if (ft_col_up(board) == 0 || ft_col_down(board) == 0)
	{
		return (0);
	}
	if (ft_row_left(board) == 0 || ft_row_right(board) == 0)
	{
		return (0);
	}
	return (1);
}

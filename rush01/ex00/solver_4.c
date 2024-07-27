/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:52:28 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/21 19:40:26 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_sol(int board[6][6]);

int		ft_valid(int board[6][6]);

int	ft_is_safe(int board[6][6], int row, int col, int nb)
{
	int	c;
	int	r;

	c = col;
	while (c > 1)
	{
		c--;
		if (board[row][c] == nb)
		{
			return (0);
		}
	}
	r = row;
	while (r > 1)
	{
		r--;
		if (board[r][col] == nb)
		{
			return (0);
		}
	}
	return (1);
}

int	ft_solve(int board[6][6], int s, int *count)
{
	int	row;
	int	col;
	int	i;

	row = (s / 4) + 1;
	col = (s % 4) + 1;
	if (s < 16)
	{
		i = 0;
		while (++i < 5)
		{
			if (ft_is_safe(board, row, col, i) == 1)
			{
				board[row][col] = i;
				ft_solve(board, s + 1, count);
				board[row][col] = 0;
			}
		}
	}
	else if (ft_valid(board) == 1)
	{
		*count += 1;
		print_sol(board);
	}
	return (*count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:15:35 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/21 19:44:50 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	build_grid(int board[6][6])
{
	int	x;
	int	y;

	x = 0;
	while (x < 6)
	{
		y = 0;
		while (y < 6)
		{
			board[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	add_input(int board[6][6], int str[16])
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		board[0][i] = str[i - 1];
		i++;
	}
	while (i <= 8)
	{
		board[5][i - 4] = str[i - 1];
		i++;
	}
	while (i <= 12)
	{
		board[i - 8][0] = str[i - 1];
		i++;
	}
	while (i <= 16)
	{
		board[i - 12][5] = str[i - 1];
		i++;
	}
}

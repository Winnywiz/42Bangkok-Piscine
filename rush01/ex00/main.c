/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:17:07 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/21 19:49:47 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	build_grid(int board[6][6]);

void	add_input(int board[6][6], int str[16]);

int		ft_solve(int board[6][6], int s, int *count);

int		ft_strlen(char *str);

void	print_sol(int board[6][6]);

int	str_to_int(char *argv, int *input)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (argv[i] != '\0')
	{
		if ((argv[i] < '1' || argv[i] > '4') && argv[i] != ' ')
		{
			return (0);
		}
		else if (argv[i] >= '1' && argv[i] <= '4' && \
		(argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			input[c++] = argv[i] - '0';
		i++;
	}
	if (c != 16)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	board[6][6];
	int	i;
	int	input_str[16];

	build_grid(board);
	if (argc == 2 && ft_strlen(argv[1]) == 31)
	{
		if (!str_to_int(argv[1], input_str))
			write(1, "Error", 5);
		else
		{
			i = 0;
			add_input(board, input_str);
			if (ft_solve(board, 0, &i) == 0)
				write(1, "No Solutions", 12);
		}
	}
	else
		write(1, "Error", 5);
	return (0);
}

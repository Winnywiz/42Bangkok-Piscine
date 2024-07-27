/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctharawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:48:35 by ctharawi          #+#    #+#             */
/*   Updated: 2024/07/14 22:27:50 by ctharawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	rush(int x, int y);

int	atoi(char *strg)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while ((strg[i] != '\0') && (strg[i] != '.'))
	{
		if ((strg[i] < 48) || (strg[i] > 57))
		{
			break ;
		}
		res = res * 10 + (strg[i] - '0');
		i++;
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (argc == 3)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		if ((x == 0) || (y == 0))
		{
			write (0, "Error with input running with defual. . .\n", 42);
			rush(5, 5);
			return (0);
		}
		rush (x, y);
	}
	if (argc == 1)
	{
		rush(5, 5);
		return (0);
	}
	return (0);
}

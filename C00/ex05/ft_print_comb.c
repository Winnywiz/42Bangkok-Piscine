/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:36:30 by skanin            #+#    #+#             */
/*   Updated: 2024/07/11 10:36:36 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				write(1, comb, 3);
				if (!(comb[0] == '7' && comb[1] == '8' && comb[2] == '9'))
				{
					write(1, ", ", 2);
				}
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}

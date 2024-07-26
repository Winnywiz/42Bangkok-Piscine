/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:26:38 by skanin            #+#    #+#             */
/*   Updated: 2024/07/15 16:45:03 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*start;
	int	*end;
	int	decay;

	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		decay = *start;
		*start = *end;
		*end = decay;
		start++;
		end--;
	}
}

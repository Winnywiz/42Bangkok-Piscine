/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:42:55 by skanin            #+#    #+#             */
/*   Updated: 2024/07/28 23:50:47 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	nb_len;

	index = 0;
	nb_len = max - min;
	if (nb_len <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc(nb_len * sizeof(int));
	while (index < nb_len)
		range[0][index++] = min++;
	return (nb_len);
}

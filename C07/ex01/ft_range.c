/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:32:16 by skanin            #+#    #+#             */
/*   Updated: 2024/07/28 23:49:14 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	index;
	int	range;
	int	*arrays;

	index = 0;
	range = max - min;
	if (range <= 0)
		return (NULL);
	arrays = (int *) malloc(range * sizeof(int));
	while (min < max)
		arrays[index++] = min++;
	return (arrays);
}

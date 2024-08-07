/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:26:38 by skanin            #+#    #+#             */
/*   Updated: 2024/07/15 18:38:40 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*start;
	int	*end;
	int	decay;
	int	i;

	i = 0;
	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		decay = *start;
		*start = *end;
		*end = decay;
		start++;
		end--;
		i++;
	}
}
#include <stdio.h>
int	main(){
	int arr[] = {1,2,3,4};
	int size = 4;

	ft_rev_int_tab(arr, size);

	for(int i = 0; i < size; i++)
	{
	printf("%d", arr[i]);
			}
}

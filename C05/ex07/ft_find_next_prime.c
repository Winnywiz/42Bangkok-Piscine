/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:27:03 by skanin            #+#    #+#             */
/*   Updated: 2024/07/27 21:16:47 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	start;
	int	found;

	start = 1;
	found = 0;
	while (start <= nb)
	{
		if (nb % start == 0)
			found++;
		start++;
	}
	if (found == 2)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(2147446));
}

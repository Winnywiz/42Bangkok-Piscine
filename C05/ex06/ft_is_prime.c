/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:08:39 by skanin            #+#    #+#             */
/*   Updated: 2024/07/26 16:26:09 by skanin           ###   ########.fr       */
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

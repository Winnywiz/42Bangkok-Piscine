/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:29:08 by skanin            #+#    #+#             */
/*   Updated: 2024/07/25 14:58:18 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	result;

	result = 1;
	if (nb <= 0)
		return (0);
	while (result * result < nb)
	{
		result++;
	}
	if (result * result == nb)
		return (result);
	return (0);
}

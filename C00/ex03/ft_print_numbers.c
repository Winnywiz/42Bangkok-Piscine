/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:24:22 by skanin            #+#    #+#             */
/*   Updated: 2024/07/09 18:28:48 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	alphabet;

	alphabet = '0';
	while (alphabet <= '9')
	{
		write(1, &alphabet, 1);
		alphabet++;
	}
}

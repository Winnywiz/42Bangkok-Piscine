/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:24:03 by skhaziev          #+#    #+#             */
/*   Updated: 2024/07/28 17:33:44 by aazanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h" 

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (!(*s1 == 0 && *s2 == 0))
	{
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

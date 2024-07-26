/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:55:48 by skanin            #+#    #+#             */
/*   Updated: 2024/07/19 19:51:27 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*og_dest;

	og_dest = dest;
	dest = dest + ft_strlen(dest);
	while (nb > 0)
	{
		if (*src == '\0')
		{
			break ;
		}
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (og_dest);
}

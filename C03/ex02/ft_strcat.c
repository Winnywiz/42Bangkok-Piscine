/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:28:47 by skanin            #+#    #+#             */
/*   Updated: 2024/07/19 19:50:32 by skanin           ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	char	*og_dest;

	og_dest = dest;
	dest = dest + ft_strlen(dest);
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (og_dest);
}

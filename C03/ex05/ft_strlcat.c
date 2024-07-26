/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:32:08 by skanin            #+#    #+#             */
/*   Updated: 2024/07/21 16:18:13 by skanin           ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				index;
	unsigned int	d_size;
	unsigned int	s_size;

	index = 0;
	s_size = ft_strlen(src);
	d_size = ft_strlen(dest);
	while (index < (int)(size - d_size - 1))
	{
		if (src[index] == '\0')
			break ;
		else
			dest[d_size + index] = src[index];
		index++;
	}
	dest[d_size + index] = '\0';
	return (d_size + s_size);
}

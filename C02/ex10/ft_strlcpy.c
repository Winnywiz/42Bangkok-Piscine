/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <winnyscge@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 02:26:38 by skanin            #+#    #+#             */
/*   Updated: 2024/07/17 20:16:45 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	s_size;
	int				i;

	s_size = 0;
	while (src[s_size] != '\0')
	{
		s_size++;
	}
	i = 0;
	while (src[i] != '\0' && i < ((int)size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
	{
		dest[i] = '\0';
	}
	return (s_size);
}

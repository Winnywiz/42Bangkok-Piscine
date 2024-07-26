/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <winnyscge@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:43:17 by skanin            #+#    #+#             */
/*   Updated: 2024/07/18 17:39:05 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*proc;

	proc = dest;
	while (*src != '\0')
	{
		*proc++ = *src++;
	}
	*proc = '\0';
	return (dest);
}

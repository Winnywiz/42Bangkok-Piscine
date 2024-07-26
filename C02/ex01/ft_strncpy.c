/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <winnyscge@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:21:08 by skanin            #+#    #+#             */
/*   Updated: 2024/07/16 19:49:19 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*proc;

	proc = dest;
	while (*src != '\0' && n > 0)
	{
		*proc++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*proc++ = '\0';
		n--;
	}
	return (dest);
}

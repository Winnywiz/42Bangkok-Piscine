/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:51:24 by skanin            #+#    #+#             */
/*   Updated: 2024/07/29 01:49:53 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_malloc(int size)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *) malloc(size);
	while (index < size)
		str[index++] = '\0';
	return (str);
}

char	*ft_strupdate(char **src, char *sep, int size, int length)
{
	char	*strings;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	strings = ft_malloc(length);
	while (i < size)
	{
		k = 0;
		while (j < length)
		{
			if (src[i][k] == '\0')
			{
				k = 0;
				while (sep[k] != '\0')
					strings[j++] = sep[k++];
				break ;
			}
			strings[j++] = src[i][k++];
		}
		i++;
	}
	return (strings);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	int		index;
	int		total_length;
	int		sep_length;
	int		str_length;
	char	*strings;

	index = 0;
	total_length = 0;
	sep_length = ft_strlen(sep);
	while (index < size)
	{
		str_length = ft_strlen(str[index]);
		if (index != size -1)
			total_length += str_length + sep_length;
		else
			total_length += str_length + 1;
		index++;
	}
	strings = ft_strupdate(str, sep, size, total_length);
	strings[total_length - 1] = '\0';
	return (strings);
}
/*
int	main(void)
{
	char	*str[] = {"win4234324", "is_", "good"};
	char	sep[] = "       :";
	char	*str_;

	str_ = ft_strjoin(3, str, sep);
	printf("%s", str_);
	free(str_);
}
*/

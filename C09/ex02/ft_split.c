/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:46:23 by skanin            #+#    #+#             */
/*   Updated: 2024/08/02 00:28:33 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int	f t_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	j;
	int	found;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	found = 1;
	while (str[i])
	{
		if (j == ft_strlen(charset))
		{
			j = 0;
			found++;
		}
		else if (str[i] == charset[j])
			j++;
		i++;
	}
	return (found);
}
char	**ft_split(char *str, char *charset)
{
	int	fcount_word;
	char	**r_split;

	fcount_word = count_word(str, charset);
	r_split = (char **) malloc(1);
	return (r_split);
}
int	main(void)
{
	int	i;
	int	j;
	char	**r_split;
	char	*str;
	char	*delim;

	str = ", OK, ABC, DEF";
	delim = ", ";
	j = count_word(str, delim);
	printf("%d", j);
}

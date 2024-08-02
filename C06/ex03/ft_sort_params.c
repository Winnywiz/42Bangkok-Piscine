/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:03:20 by skanin            #+#    #+#             */
/*   Updated: 2024/07/28 21:44:23 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*_s1;
	unsigned char	*_s2;

	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	while (*_s1 != '\0' || *_s2 != '\0')
	{
		if (*_s1 != *_s2)
		{
			break ;
		}
		_s1++;
		_s2++;
	}
	return (*_s1 - *_s2);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	ft_printarr(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		write(1, argv[index], ft_strlen(argv[index]));
		write(1, "\n", 1);
		index++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*copy;

	i = 0;
	while (i < argc)
	{
		j = 1;
		k = j + 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[k]) > 0)
			{
				copy = argv[j];
				argv[j] = argv[k];
				argv[k] = copy;
			}
			j++;
			k++;
		}
		i++;
	}
	ft_printarr(argc, argv);
}

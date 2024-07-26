/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 04:35:21 by skanin            #+#    #+#             */
/*   Updated: 2024/07/19 19:49:00 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*get_ptr;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (j == 0)
				get_ptr = (str + i);
			j++;
		}
		else
			j = 0;
		if (j == ft_strlen(to_find))
			return (get_ptr);
		i++;
	}
	return (0);
}

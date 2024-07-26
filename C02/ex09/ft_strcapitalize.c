/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <winnyscge@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:02:09 by skanin            #+#    #+#             */
/*   Updated: 2024/07/18 17:38:39 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*sentence_chain(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str -= 32;
	}
	while (*str != '\0')
	{
		str++;
		if (*str >= 'a' && *str <= 'z')
		{
		}
		else if (*str >= '1' && *str <= '9')
		{
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		else
		{
			break ;
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char	*proc;

	proc = str;
	while (*proc != '\0')
	{
		if ((*proc >= 'A' && *proc <= 'Z') || (*proc >= 'a' && *proc <= 'z'))
		{
			proc = sentence_chain(proc);
		}
		else if (*proc >= '1' && *proc <= '9')
		{
			proc = sentence_chain(proc);
		}
		proc++;
	}
	*proc = '\0';
	return (str);
}

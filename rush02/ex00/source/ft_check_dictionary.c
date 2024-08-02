/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaziev <skhaziev@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:00:09 by skhaziev          #+#    #+#             */
/*   Updated: 2024/07/28 19:05:17 by skhaziev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h"

int	ft_check_exist_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (close(fd) < 0)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	return (0);
}

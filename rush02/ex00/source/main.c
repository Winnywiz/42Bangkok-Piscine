/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 09:41:44 by skhaziev          #+#    #+#             */
/*   Updated: 2024/07/28 23:17:10 by aazanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_strcmp(argv[1], "0")))
			ft_output("0", "numbers.dict");
		if (ft_check_exist_file("numbers.dict"))
			return (144);
		ft_parser(argv[1], "numbers.dict");
	}
	else if (argc == 3)
	{
		if (!(ft_strcmp(argv[2], "0")))
			ft_output("0", argv[1]);
		if (ft_check_exist_file(argv[1]))
			return (145);
		ft_parser(argv[2], argv[1]);
	}
	else
	{
		ft_putstr("Error");
		return (135);
	}
	return (0);
}

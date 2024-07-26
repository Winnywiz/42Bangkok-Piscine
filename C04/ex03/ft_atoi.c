/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:00:16 by skanin            #+#    #+#             */
/*   Updated: 2024/07/22 17:30:56 by skanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	conversion;

	conversion = 0;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			conversion++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (10 * nb) + (str[i] - '0');
		i++;
	}
	if (conversion % 2 != 0)
		nb = -nb;
	return (nb);
}
/*
int	main(int argc, char *argv[])
{
	(void) argc;
	if (argc == 2)
		printf("%d", ft_atoi(argv[1]));
}
*/

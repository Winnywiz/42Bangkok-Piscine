/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:52:05 by aazanov           #+#    #+#             */
/*   Updated: 2024/07/28 23:28:25 by aazanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h"

int	ft_parser(char *nums, char *dict)
{
	int	*arg_num;
	int	*arg_digit;
	int	i;
	int	size;

	i = 0;
	size = len_num(nums);
	arg_num = (int *)(malloc(sizeof(int) * len_num(nums)));
	arg_digit = (int *)(malloc(sizeof(int) * len_num(nums)));
	while (nums[i] != '\0')
	{
		arg_num[i] = nums[i] - '0';
		arg_digit[i] = --size;
		i++;
	}
	if (ft_sendler(arg_num, arg_digit, i, dict))
		return (1);
	return (0);
}

char	**create_num_sendler(int *num, int *digit, int size)
{
	char		**arr_res;
	int			n;
	int			i;
	t_casino	params;

	arr_res = (char **)malloc(sizeof(char *) * size * 2);
	n = 0;
	i = 0;
	params.arr_res = arr_res;
	params.num = num;
	params.digit = digit;
	params.n = &n;
	params.i = &i;
	while (n != size)
	{
		arr_res[i] = (char *)malloc(sizeof(char) * 100);
		if (digit[n] % 3 == 2)
			process_digit_mod_2(&params);
		else if (digit[n] % 3 == 1)
			process_digit_mod_1(&params);
		else
			process_digit_mod_0(&params);
	}
	return (arr_res);
}

int	ft_sendler(int *num, int *digit, int size, char *dict)
{
	int		i;
	char	**res;

	i = 0;
	res = create_num_sendler(num, digit, size);
	while (res[i] != 0)
	{
		ft_output(res[i++], dict);
		if (res[i + 1] != 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	while (i != 0)
		free(res[--i]);
	free(res);
	free(num);
	free(digit);
	return (0);
}

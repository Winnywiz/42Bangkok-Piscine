/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_casino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:55:42 by aazanov           #+#    #+#             */
/*   Updated: 2024/07/28 23:09:09 by aazanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prototypes.h"

void	process_digit_mod_2(t_casino *params)
{
	if (params->num[*params->n] != 0)
	{
		params->arr_res[*params->i] = rever(params->num[*params->n]);
		params->arr_res[++(*params->i)] = (char *)malloc(sizeof(char) * 100);
		params->arr_res[\
		*params->i] = rever(ten_pow(params->digit[(*params->n)++] % 3));
		(*params->i)++;
	}
	else
		(*params->n)++;
}

void	process_digit_mod_1(t_casino *params)
{
	if ((params->num[*params->n] * ten_pow(1)) < 20)
	{
		if (params->num[*params->n] != 0)
		{
			params->arr_res[\
			*params->i] = rever((params->num[\
			*params->n] * ten_pow(1)) + params->num[*params->n + 1]);
			params->arr_res[\
			++(*params->i)] = (char *)malloc(sizeof(char) * 100);
			params->arr_res[\
			*params->i] = ten_str(params->digit[++(*params->n)]);
			(*params->i)++;
		}
		(*params->n)++;
	}
	else
		params->arr_res[\
		(*params->i)++] = rever(params->num[(*params->n)++] * ten_pow(1));
}

void	process_digit_mod_0(t_casino *params)
{
	if (params->num[*params->n] != 0)
	{
		params->arr_res[*params->i] = rever(params->num[*params->n]);
		params->arr_res[++(*params->i)] = (char *)malloc(sizeof(char) * 100);
		params->arr_res[*params->i] = ten_str(params->digit[(*params->n)++]);
		(*params->i)++;
	}
	else
	{
		if (params->num[*params->n - 1] != 0)
			params->arr_res[\
			(*params->i)++] = ten_str(params->digit[(*params->n)++]);
		else
			(*params->n)++;
	}
}

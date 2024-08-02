/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazanov <aazanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:23:00 by skhaziev          #+#    #+#             */
/*   Updated: 2024/07/28 22:42:42 by aazanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct t_casino
{
	char	**arr_res;
	int		*num;
	int		*digit;
	int		*n;
	int		*i;
}	t_casino;

void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ten_pow(int x);
int		ft_sendler(int *num, int *digit, int size, char *dict);
int		ft_check_exist_file(char *file_name);
int		ft_parser(char *str, char *dict);
int		ft_output(char *digit, char *dictionary_file);
char	*rever(int nb);
int		len_num(char *num_str);
char	*ten_str(int x);
void	process_digit_mod_0(t_casino *params);
void	process_digit_mod_1(t_casino *params);
void	process_digit_mod_2(t_casino *params);
int		ft_strcmp(char *s1, char *s2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:50:04 by skanin            #+#    #+#             */
/*   Updated: 2024/07/31 14:23:13 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRAL_H
# define CENTRAL_H
# include "ft_map.h"
# include "ft.h"

void	print_summary(t_map *map, int max_length);
void	build_square(t_map *map, int x, int y, int size);
void	compute_square(t_map *map);
int		search_square(int fd);
int		**fill_matrix(t_map *map);

#endif

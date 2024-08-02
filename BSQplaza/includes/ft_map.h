/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:12 by ludomsak          #+#    #+#             */
/*   Updated: 2024/07/31 14:22:20 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
# include "ft_file.h"

typedef struct s_map
{
	int		width;
	int		height;
	int		h_length;
	int		**matrix;
	char	empty;
	char	obstacle;
	char	fill;
	t_file	*file;
}	t_map;

typedef struct s_tool
{
	int	i;
	int	j;
	int	k;
	int	x;
	int	y;
	int	index;
	int	length;
	int	ascii[256];
}	t_tool;

t_map	*load_map(int fd);
t_tool	build_tool(void);
int		map_header(t_map *map, unsigned char *map_content);
int		**build_matrix(t_map *map);

#endif

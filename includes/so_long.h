/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:51:25 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/27 23:35:12 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_items
{
	t_pos			pos;
}				t_items;

typedef struct	s_map
{
	char		**map;
	t_pos		start;
	int			items_count;
	t_items		*items;
	int			width;
	int			height;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*path;
	int			width;
	int			height;
}				t_img;

typedef struct	s_data
{
	void		*mlx;
	void		*window;
	t_map		map;
	
	t_img		ground;
	t_img		wall;
	t_img		player;
	t_img		item1;
	t_img		item2;
	t_img		item3;
	t_img		exit;

}				t_data;


# include "../mlx/mlx.h"
# include "ft_utils.h"

#endif
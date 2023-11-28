/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:51:25 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/28 22:57:33 by drenassi         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>

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
	t_pos		exit;
	int			items_count;
	t_items		*items;
	int			width;
	int			height;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
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
	t_pos		pos;
	t_img		player;
	t_img		ground;
	t_img		wall;
	t_img		item;
	t_img		exit;
}				t_data;


# include "../mlx/mlx.h"
# include "ft_utils.h"
# include "ft_printf.h"

#endif
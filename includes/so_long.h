/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:51:25 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 00:32:31 by drenassi         ###   ########.fr       */
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
# include "../mlx/mlx.h"
# include "ft_utils.h"
# include "ft_printf.h"

/********************************** POSITION **********************************/
typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

/*********************************** ITEMS ************************************/
typedef struct s_items
{
	t_pos			pos;
}				t_items;

/************************************ MAP *************************************/
typedef struct s_map
{
	char		**map;
	t_pos		start;
	t_pos		exit;
	int			items_count;
	t_items		*items;
	int			width;
	int			height;
}				t_map;

/*********************************** IMAGE ************************************/
typedef struct s_img
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

/*********************************** INPUTS ***********************************/
typedef struct s_inp
{
	int			anim;
	int			right;
	int			left;
	int			up;
	int			down;
}				t_inp;

/********************************** ALL DATAS *********************************/
typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			clock;
	t_inp		inp;
	t_map		map;
	t_pos		pos;
	t_img		player;
	t_img		ground;
	t_img		wall;
	t_img		item;
	t_img		exit;
}				t_data;

/********************************* DRAW INIT **********************************/
void	ft_print_img(t_data *data, t_img *img, int x, int y);
void	ft_init_img(t_data *data, t_img *img, char *path);
void	ft_init_imgs(t_data *data);
void	ft_init_inputs(t_data *data);
void	ft_draw_map(t_data *data);

/******************************** DRAW PLAYER *********************************/
void	ft_draw_above(t_data *data, t_img img, int x, int y);
void	ft_right(t_data *data);
void	ft_left(t_data *data);
void	ft_up(t_data *data);
void	ft_down(t_data *data);

#endif
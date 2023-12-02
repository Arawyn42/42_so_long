/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:37:06 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 11:47:18 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

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
	int			win;
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
	int			moves;
	t_inp		inp;
	t_map		map;
	t_pos		pos;
	t_img		player;
	t_img		ground;
	t_img		wall;
	t_img		item;
	t_img		exit;
	t_img		win;
}				t_data;

#endif
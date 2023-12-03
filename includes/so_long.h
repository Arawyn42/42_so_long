/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:51:25 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/03 17:28:41 by drenassi         ###   ########.fr       */
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
# include "ft_struct.h"
# include "ft_utils.h"
# include "ft_printf.h"

/********************************* DRAW INIT **********************************/
void	ft_print_img(t_data *data, t_img *img, int x, int y);
void	ft_init_img(t_data *data, t_img *img, char *path);
void	ft_init_imgs(t_data *data);
void	ft_init_inputs(t_data *data);
int     ft_draw_map(t_data *data);

/******************************** DRAW PLAYER *********************************/
t_img	ft_img_cpy(t_data *data, t_img img);
void	ft_draw_above(t_data *data, t_img img, int x, int y);
void	ft_right(t_data *data);
void	ft_left(t_data *data);
void	ft_up(t_data *data);
void	ft_down(t_data *data);

/************************************ DRAW ************************************/
void	ft_draw_score(t_data *data);
int     ft_refresh(t_data *data);
int	    ft_key_pressed(int key, t_data *data);
void	ft_create_window(t_data *data, int w, int h);

/****************************** END OF THE GAME *******************************/
int     ft_close(t_data *data);
void	ft_win_game(t_data *data);

#endif
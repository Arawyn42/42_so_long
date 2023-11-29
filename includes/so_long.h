/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:51:25 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 00:38:34 by drenassi         ###   ########.fr       */
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
void	ft_draw_map(t_data *data);

/******************************** DRAW PLAYER *********************************/
void	ft_draw_above(t_data *data, t_img img, int x, int y);
void	ft_right(t_data *data);
void	ft_left(t_data *data);
void	ft_up(t_data *data);
void	ft_down(t_data *data);

#endif
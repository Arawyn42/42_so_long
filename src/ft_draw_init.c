/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:35:13 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:37 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img->img,
		x * img->width, y * img->height);
}

void	ft_init_img(t_data *data, t_img *img, char *path)
{
	if (img->img)
		mlx_destroy_image(data->mlx, img->img);
	img->width = 64;
	img->height = 64;
	img->path = path;
	img->img = mlx_xpm_file_to_image(data->mlx, img->path,
			&(img->width), &(img->height));
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_length), &(img->endian));
}

void	ft_init_imgs(t_data *data)
{
	data->clock = 0;
	data->moves = 0;
	data->ground.img = NULL;
	ft_init_img(data, &(data->ground), "./sprites/ground.xpm");
	data->player.img = NULL;
	ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
	ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	data->wall.img = NULL;
	ft_init_img(data, &(data->wall), "./sprites/wall.xpm");
	data->exit.img = NULL;
	ft_init_img(data, &(data->exit), "./sprites/exit1.xpm");
	data->item.img = NULL;
	ft_init_img(data, &(data->item), "./sprites/item1.xpm");
	data->score.img = NULL;
	ft_init_img(data, &(data->score), "./sprites/score_screen.xpm");
	data->win.img = NULL;
	ft_init_img(data, &(data->win), "./sprites/win.xpm");
	data->win.width = 256;
	data->win.height = 256;
}

void	ft_init_inputs(t_data *data)
{
	data->inp.anim = 0;
	data->inp.right = 0;
	data->inp.left = 0;
	data->inp.up = 0;
	data->inp.down = 0;
	data->inp.win = 0;
}

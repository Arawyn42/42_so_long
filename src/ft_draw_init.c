/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:35:13 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 13:39:33 by drenassi         ###   ########.fr       */
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

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map && data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '0')
				ft_print_img(data, &(data->ground), x, y);
			else if (data->map.map[y][x] == '1')
				ft_print_img(data, &(data->wall), x, y);
			else if (data->map.map[y][x] == 'C')
				ft_print_img(data, &(data->item), x, y);
			else if (data->map.map[y][x] == 'E')
				ft_print_img(data, &(data->exit), x, y);
			x++;
		}
		y++;
	}
	ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	ft_draw_score(data);
}

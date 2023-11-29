/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:13:34 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 00:19:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_up_ground(t_data *data)
{
	if (data->clock == 8000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_up3_1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_up3_2.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y - 1);
	}
	if (data->clock == 12000)
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_up4.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y - 1);
		data->map.map[data->pos.y][data->pos.x] = '0';
	}
	if (data->clock == 16000)
	{
		data->pos.y -= 1;
		data->map.map[data->pos.y][data->pos.x] = 'P';
		ft_init_img(data, &(data->player), "./sprites/player_up1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_up(t_data *data)
{
	if (data->clock == 10 && data->inp.up)
	{
		ft_init_img(data, &(data->player), "./sprites/player_up1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
	if (data->map.map[data->pos.y - 1][data->pos.x] == '0' && data->inp.up)
	{
		if (data->clock == 4000)
		{
			ft_init_img(data, &(data->player), "./sprites/player_up2.xpm");
			ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		}
		ft_up_ground(data);
	}
	if (data->clock == 24000)
		data->inp.up = 0;
}

static void	ft_down_ground(t_data *data)
{
	if (data->clock == 8000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down3_1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_down3_2.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 12000)
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_down4.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y + 1);
		data->map.map[data->pos.y][data->pos.x] = '0';
	}
	if (data->clock == 16000)
	{
		data->pos.y += 1;
		data->map.map[data->pos.y][data->pos.x] = 'P';
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_down(t_data *data)
{
	if (data->clock == 10 && data->inp.down)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
	if (data->map.map[data->pos.y + 1][data->pos.x] == '0' && data->inp.down)
	{
		if (data->clock == 4000)
		{
			ft_init_img(data, &(data->player), "./sprites/player_down2.xpm");
			ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		}
		ft_down_ground(data);
	}
	if (data->clock == 24000)
		data->inp.down = 0;
}

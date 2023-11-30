/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:13:34 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 19:25:24 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void ft_down_item_anim(t_data *data)
{
	if (data->clock == 6000)
	{
		ft_init_img(data, &(data->item), "./sprites/item2.xpm");
		ft_print_img(data, &data->item, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 12000)
	{
		ft_init_img(data, &(data->item), "./sprites/item3.xpm");
		ft_print_img(data, &data->item, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 18000)
	{
		(data->map.items_count)--;
		free(data->map.items);
		data->map.map[data->pos.y + 1][data->pos.x] = 'D';
		ft_get_items_pos(&data->map);
	}
}

static void	ft_down_anim2(t_data *data, t_img start_img, t_img end_img)
{
	if (data->clock == 8000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down3_1.xpm");
		ft_draw_above(data, start_img, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_down3_2.xpm");
		ft_draw_above(data, end_img, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 12000)
	{
		ft_print_img(data, &start_img, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_down4.xpm");
		ft_draw_above(data, end_img, data->pos.x, data->pos.y + 1);
		data->map.map[data->pos.y][data->pos.x] = data->pos.c;
	}
	if (data->clock == 16000)
	{
		data->pos.y += 1;
		data->pos.c = data->map.map[data->pos.y][data->pos.x];
		data->map.map[data->pos.y][data->pos.x] = 'P';
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, end_img, data->pos.x, data->pos.y);
	}
}

static void	ft_down_anim(t_data *data)
{
	t_img	start_img;
	t_img	end_img;

	start_img = data->ground;
	if (data->pos.c == 'D')
		start_img = data->item;
	end_img = data->ground;
	if (data->map.map[data->pos.y + 1][data->pos.x] == 'D')
		end_img = data->item;
	if (data->clock == 4000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down2.xpm");
		ft_draw_above(data, start_img, data->pos.x, data->pos.y);
	}
	ft_down_anim2(data, start_img, end_img);
}

void	ft_down(t_data *data)
{
	t_img	img;

	if (data->pos.c == '0')
		img = data->ground;
	else if (data->pos.c == 'D')
		img = data->item;
	if (data->clock == 10 && data->inp.down)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, img, data->pos.x, data->pos.y);
	}
	if (data->map.map[data->pos.y + 1][data->pos.x] == '0' && data->inp.down)
	{
		ft_down_anim(data);
	}
	if (data->map.map[data->pos.y + 1][data->pos.x] == 'C' && data->inp.down)
		ft_down_item_anim(data);
	if (data->map.map[data->pos.y + 1][data->pos.x] == 'D' && data->inp.down)
		ft_down_anim(data);
	if (data->clock == 18000)
		data->inp.down = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:13:34 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 20:22:32 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_down_item_anim(t_data *data)
{
	if (data->clock == 0)
		data->inp.anim = 2;
	if (data->clock == 2000)
	{
		ft_init_img(data, &(data->item), "./sprites/item2.xpm");
		ft_print_img(data, &data->item, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 5000)
	{
		ft_init_img(data, &(data->item), "./sprites/item3.xpm");
		ft_print_img(data, &data->item, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 8000)
	{
		(data->map.items_count)--;
		free(data->map.items);
		data->map.map[data->pos.y + 1][data->pos.x] = 'D';
		ft_get_items_pos(&data->map);
	}
}

static void	ft_down_anim2(t_data *data, t_img start_img, t_img end_img)
{
	if (data->clock == 4000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down3_1.xpm");
		ft_draw_above(data, start_img, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_down3_2.xpm");
		ft_draw_above(data, end_img, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 6000)
	{
		ft_print_img(data, &start_img, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_down4.xpm");
		ft_draw_above(data, end_img, data->pos.x, data->pos.y + 1);
	}
	if (data->clock == 8000)
	{
		data->pos.y += 1;
		data->moves += 1;
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, end_img, data->pos.x, data->pos.y);
	}
}

static void	ft_down_anim(t_data *data)
{
	t_img	start_img;
	t_img	end_img;

	if (data->clock == 0)
		data->inp.anim = 1;
	start_img = data->ground;
	if (data->map.map[data->pos.y][data->pos.x] == 'D')
		start_img = data->item;
	if (data->map.map[data->pos.y][data->pos.x] == 'E')
		start_img = data->exit;
	end_img = data->ground;
	if (data->map.map[data->pos.y + 1][data->pos.x] == 'D')
		end_img = data->item;
	if (data->map.map[data->pos.y + 1][data->pos.x] == 'E')
		end_img = data->exit;
	if (data->clock == 2000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down2.xpm");
		ft_draw_above(data, start_img, data->pos.x, data->pos.y);
	}
	ft_down_anim2(data, start_img, end_img);
}

static void	ft_down2(t_data *data, t_img img)
{
	if (((data->map.map[data->pos.y + 1][data->pos.x] == '0'
			|| data->map.map[data->pos.y + 1][data->pos.x] == 'D'
		|| data->map.map[data->pos.y + 1][data->pos.x] == 'E')
		&& data->inp.down && !data->inp.anim) || data->inp.anim == 1)
		ft_down_anim(data);
	if ((data->map.map[data->pos.y + 1][data->pos.x] == 'C'
		&& data->inp.down && !data->inp.anim) || data->inp.anim == 2)
		ft_down_item_anim(data);
	if ((data->map.map[data->pos.y + 1][data->pos.x] == 'M'
		&& data->inp.down && !data->inp.anim) || data->inp.anim == 3)
		ft_down_enemy_anim(data, img);
	if (data->clock == 8050 && data->inp.anim != 3)
	{
		data->inp.anim = 0;
		data->inp.down = 0;
		ft_draw_score(data);
		if (data->map.map[data->pos.y][data->pos.x] == 'E'
			&& data->map.items_count == 0)
			data->inp.win = 1;
	}
}

void	ft_down(t_data *data)
{
	t_img	img;

	if (data->map.map[data->pos.y][data->pos.x] == 'D')
		img = data->item;
	else if (data->map.map[data->pos.y][data->pos.x] == 'E')
		img = data->exit;
	else
		img = data->ground;
	if (data->clock == 10 && data->inp.down)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, img, data->pos.x, data->pos.y);
	}
	ft_down2(data, img);
}

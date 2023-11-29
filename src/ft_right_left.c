/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:13:30 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 00:25:55 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_right_ground(t_data *data)
{
	if (data->clock == 8000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_right3_1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_right3_2.xpm");
		ft_draw_above(data, data->ground, data->pos.x + 1, data->pos.y);
	}
	if (data->clock == 12000)
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_right4.xpm");
		ft_draw_above(data, data->ground, data->pos.x + 1, data->pos.y);
		data->map.map[data->pos.y][data->pos.x] = '0';
	}
	if (data->clock == 16000)
	{
		data->pos.x += 1;
		data->map.map[data->pos.y][data->pos.x] = 'P';
		ft_init_img(data, &(data->player), "./sprites/player_right1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_right(t_data *data)
{
	if (data->clock == 10 && data->inp.right)
	{
		ft_init_img(data, &(data->player), "./sprites/player_right1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
	if (data->map.map[data->pos.y][data->pos.x + 1] == '0' && data->inp.right)
	{
		if (data->clock == 4000)
		{
			ft_init_img(data, &(data->player), "./sprites/player_right2.xpm");
			ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		}
		ft_right_ground(data);
	}
	if (data->clock == 24000)
		data->inp.right = 0;
}

static void	ft_left_ground(t_data *data)
{
	if (data->clock == 8000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_left3_1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_left3_2.xpm");
		ft_draw_above(data, data->ground, data->pos.x - 1, data->pos.y);
	}
	if (data->clock == 12000)
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		ft_init_img(data, &(data->player), "./sprites/player_left4.xpm");
		ft_draw_above(data, data->ground, data->pos.x - 1, data->pos.y);
		data->map.map[data->pos.y][data->pos.x] = '0';
	}
	if (data->clock == 16000)
	{
		data->pos.x -= 1;
		data->map.map[data->pos.y][data->pos.x] = 'P';
		ft_init_img(data, &(data->player), "./sprites/player_left1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_left(t_data *data)
{
	if (data->clock == 10 && data->inp.left)
	{
		ft_init_img(data, &(data->player), "./sprites/player_left1.xpm");
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
	if (data->map.map[data->pos.y][data->pos.x - 1] == '0' && data->inp.left)
	{
		if (data->clock == 4000)
		{
			ft_init_img(data, &(data->player), "./sprites/player_left2.xpm");
			ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
		}
		ft_left_ground(data);
	}
	if (data->clock == 24000)
		data->inp.left = 0;
}

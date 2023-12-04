/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:52:43 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 19:54:28 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_left_enemy_anim(t_data *data, t_img img)
{
	if (data->clock == 10 && !data->inp.win)
	{
		data->inp.anim = 3;
		data->inp.win = -1;
	}
	if (data->inp.win == -1 && (data->clock == 2000 || data->clock == 8000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy1.xpm");
		ft_print_img(data, &data->enemy, data->pos.x - 1, data->pos.y);
	}
	if (data->inp.win == -1 && (data->clock == 5000 || data->clock == 11000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy2.xpm");
		ft_print_img(data, &data->enemy, data->pos.x - 1, data->pos.y);
	}
	ft_lose_game(data, img);
}

void	ft_right_enemy_anim(t_data *data, t_img img)
{
	if (data->clock == 10 && !data->inp.win)
	{
		data->inp.anim = 3;
		data->inp.win = -1;
	}
	if (data->inp.win == -1 && (data->clock == 2000 || data->clock == 8000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy1.xpm");
		ft_print_img(data, &data->enemy, data->pos.x + 1, data->pos.y);
	}
	if (data->inp.win == -1 && (data->clock == 5000 || data->clock == 11000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy2.xpm");
		ft_print_img(data, &data->enemy, data->pos.x + 1, data->pos.y);
	}
	ft_lose_game(data, img);
}

void	ft_up_enemy_anim(t_data *data, t_img img)
{
	if (data->clock == 10 && !data->inp.win)
	{
		data->inp.anim = 3;
		data->inp.win = -1;
	}
	if (data->inp.win == -1 && (data->clock == 2000 || data->clock == 8000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy1.xpm");
		ft_print_img(data, &data->enemy, data->pos.x, data->pos.y - 1);
	}
	if (data->inp.win == -1 && (data->clock == 5000 || data->clock == 11000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy2.xpm");
		ft_print_img(data, &data->enemy, data->pos.x, data->pos.y - 1);
	}
	ft_lose_game(data, img);
}

void	ft_down_enemy_anim(t_data *data, t_img img)
{
	if (data->clock == 10 && !data->inp.win)
	{
		data->inp.anim = 3;
		data->inp.win = -1;
	}
	if (data->inp.win == -1 && (data->clock == 2000 || data->clock == 8000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy1.xpm");
		ft_print_img(data, &data->enemy, data->pos.x, data->pos.y + 1);
	}
	if (data->inp.win == -1 && (data->clock == 5000 || data->clock == 11000))
	{
		ft_init_img(data, &(data->enemy), "./sprites/enemy2.xpm");
		ft_print_img(data, &data->enemy, data->pos.x, data->pos.y + 1);
	}
	ft_lose_game(data, img);
}
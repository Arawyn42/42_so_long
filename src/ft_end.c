/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:36:55 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 19:47:21 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->ground.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->item.img);
	mlx_destroy_image(data->mlx, data->enemy.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->score.img);
	mlx_destroy_image(data->mlx, data->win.img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(&data->map);
	exit(EXIT_FAILURE);
	return (1);
}

void	ft_lose_game(t_data *data, t_img img)
{
	if (data->inp.win == -1 && (data->clock == 12000 || data->clock == 20000
		|| data->clock == 28000))
		ft_print_img(data, &img, data->pos.x, data->pos.y);
	if (data->inp.win == -1 && (data->clock == 16000 || data->clock == 24000))
		ft_draw_above(data, img, data->pos.x, data->pos.y);
	if (data->inp.win == -1 && data->clock == 35000)
	{
		ft_init_img(data, &data->win, "./sprites/lose.xpm");
		mlx_put_image_to_window(data->mlx, data->window, data->win.img,
			(data->map.width * 64 - data->win.width) / 2,
			(data->map.height * 64 - data->win.height) / 2);
		ft_printf("\nYou lost the game. Hmmm... Sad.\n");
		data->inp.win = 2;
		data->inp.right = 10;
		data->inp.left = 10;
		data->inp.up = 10;
		data->inp.down = 10;
	}
}

static void	ft_win_game2(t_data *data)
{
	if (data->inp.win == 1 && data->clock == 6000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_right1.xpm");
		ft_draw_above(data, data->exit, data->pos.x, data->pos.y);
	}
	if (data->inp.win == 1 && data->clock == 8000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, data->exit, data->pos.x, data->pos.y);
	}
	if (data->inp.win == 1 && data->clock == 10000)
	{
		ft_init_img(data, &(data->exit), "./sprites/exit2.xpm");
		ft_draw_above(data, data->exit, data->pos.x, data->pos.y);
	}
	if (data->inp.win == 1 && data->clock == 12000)
		ft_print_img(data, &data->exit, data->pos.x, data->pos.y);
	if (data->inp.win == 1 && data->clock == 15000)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->win.img,
			(data->map.width * 64 - data->win.width) / 2,
			(data->map.height * 64 - data->win.height) / 2);
		ft_printf("\nGG! You won the game in %d moves!\n", data->moves);
		data->inp.win = 2;
	}
}

void	ft_win_game(t_data *data)
{
	if (data->inp.win == 1 && data->inp.anim < 4)
	{
		data->inp.anim = 4;
		data->inp.right = 10;
		data->inp.left = 10;
		data->inp.up = 10;
		data->inp.down = 10;
		data->clock = 0;
	}
	if (data->inp.win == 1 && data->clock == 10)
	{
		ft_init_img(data, &(data->player), "./sprites/player_down1.xpm");
		ft_draw_above(data, data->exit, data->pos.x, data->pos.y);
	}
	if (data->inp.win == 1 && data->clock == 2000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_left1.xpm");
		ft_draw_above(data, data->exit, data->pos.x, data->pos.y);
	}
	if (data->inp.win == 1 && data->clock == 4000)
	{
		ft_init_img(data, &(data->player), "./sprites/player_up1.xpm");
		ft_draw_above(data, data->exit, data->pos.x, data->pos.y);
	}
	ft_win_game2(data);
}

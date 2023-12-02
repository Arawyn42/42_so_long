/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:36:55 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 04:34:17 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->ground.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->item.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(&data->map);
	exit(EXIT_FAILURE);
	return (1);
}

void	ft_win_game(t_data *data)
{
	if (data->map.map[data->pos.y][data->pos.x] == 'E'
		&& !data->map.items_count)
	{
		data->inp.right = 10;
		data->inp.left = 10;
		data->inp.up = 10;
		data->inp.down = 10;
		mlx_put_image_to_window(data->mlx, data->window, data->win.img,
		(data->map.width * 64 - data->win.width) / 2,
		(data->map.height * 64 - data->win.height) / 2);
		ft_printf("\n You won the game in %d moves!!!\n", data->moves);
	}
}
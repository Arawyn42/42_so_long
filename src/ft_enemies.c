/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:49:39 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 20:20:48 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/******************** Counts the number of enemies on a map *******************/
int	ft_get_enemies_count(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'M')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/***************** Gets and sets enemies positions in the map *****************/
void	ft_get_enemies_pos(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	map->enemies_count = ft_get_enemies_count(map);
	map->enemies = ft_calloc(map->enemies_count, sizeof(t_items));
	if (!map->enemies)
		return ;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'M')
			{
				map->enemies[count].pos.x = x;
				map->enemies[count].pos.y = y;
				count++;
			}
		}
	}
}

void	ft_enemies_anim(t_data *data)
{
	int	i;

	if (!data->inp.win && (data->clock2 == 10 || data->clock2 == 40000))
	{
		ft_init_img(data, &data->enemy, "./sprites/item1.xpm");
		i = 0;
		while (i < data->map.enemies_count)
		{
			ft_print_img(data, &data->enemy, data->map.enemies[i].pos.x,
				data->map.enemies[i].pos.y);
			i++;
		}
	}
	else if (!data->inp.win && (data->clock2 == 35000
			|| data->clock2 == 45000))
	{
		ft_init_img(data, &data->enemy, "./sprites/item2.xpm");
		i = 0;
		while (i < data->map.enemies_count)
		{
			ft_print_img(data, &data->enemy, data->map.enemies[i].pos.x,
				data->map.enemies[i].pos.y);
			i++;
		}
	}
}

void	ft_enemies_end_anim(t_data *data)
{
	int	i;

	if (data->clock2 == 10 || data->clock2 == 30000)
	{
		ft_init_img(data, &data->enemy, "./sprites/enemy1.xpm");
		i = 0;
		while (i < data->map.enemies_count)
		{
			ft_print_img(data, &data->enemy, data->map.enemies[i].pos.x,
				data->map.enemies[i].pos.y);
			i++;
		}
	}
	else if (data->clock2 == 15000 || data->clock2 == 40000)
	{
		ft_init_img(data, &data->enemy, "./sprites/enemy2.xpm");
		i = 0;
		while (i < data->map.enemies_count)
		{
			ft_print_img(data, &data->enemy, data->map.enemies[i].pos.x,
				data->map.enemies[i].pos.y);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:21:30 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 20:06:58 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/******** Gets the start position on the map and set it in map struct *********/
void	ft_get_exit(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'E')
			{
				map->exit.x = x;
				map->exit.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

/************* Initializes a map with start values and item count *************/
void	ft_init_map(t_data *data, char *file)
{
	data->map.map = ft_get_map(file);
	data->map.start.x = -1;
	data->map.start.y = -1;
	ft_get_start(&data->map);
	ft_get_exit(&data->map);
	ft_get_items_pos(&data->map);
	ft_get_enemies_pos(&data->map);
	data->map.width = ft_strlen(data->map.map[0]);
	data->map.height = ft_get_map_height(file);
	data->pos = data->map.start;
	data->inp.anim = 0;
}

/**************** Free the map and the collectible items array ****************/
void	ft_free_map(t_map *map)
{
	ft_free_array(map->map);
	free(map->items);
	if (map->enemies_count)
		free(map->enemies);
}

static void	ft_print_map(t_data data, int display_p)
{
	int	x;
	int	y;

	y = 0;
	while ((data.map.map)[y])
	{
		x = 0;
		write(1, "\t", 1);
		while (data.map.map[y][x])
		{
			if (x == data.pos.x && y == data.pos.y && display_p)
				write(1, "P", 1);
			else
				write(1, &data.map.map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

/************************ Prints the map in characters ************************/
void	ft_print_infos(t_data data)
{
	int		i;
	t_map	map;

	map = data.map;
	ft_printf("\t ___________________________ \n");
	ft_printf("\t|                           |\n");
	ft_printf("\t|            MAP            |\n");
	ft_printf("\t|___________________________|\n\n");
	ft_print_map(data, 1);
	ft_printf("\n\tStart position: [%d, %d]\n", map.start.x, map.start.y);
	ft_printf("\n\tPlayer position: [%d, %d]\n", data.pos.x, data.pos.y);
	ft_printf("\tExit position: [%d, %d]\n", map.exit.x, map.exit.y);
	ft_printf("\tNumber of items to collect: %d\n", map.items_count);
	ft_printf("\tItems positions:\n");
	i = -1;
	while (++i < map.items_count)
		ft_printf("\t[%d, %d]\n", map.items[i].pos.x, map.items[i].pos.y);
	ft_printf("\tNumber of enemies: %d\n", map.enemies_count);
	ft_printf("\tEnemies positions:\n");
	i = -1;
	while (++i < map.enemies_count)
		ft_printf("\t[%d, %d]\n", map.enemies[i].pos.x, map.enemies[i].pos.y);
	ft_printf("\t ___________________________ \n\n");
}

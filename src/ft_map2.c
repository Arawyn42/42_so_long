/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:21:30 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 17:22:11 by drenassi         ###   ########.fr       */
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
void	ft_init_map(t_map *map, char *file)
{
	map->map = ft_get_map(file);
	map->start.x = -1;
	map->start.y = -1;
	ft_get_start(map);
	ft_get_exit(map);
	ft_get_items_pos(map);
	map->width = ft_strlen(map->map[0]);
	map->height = ft_get_map_height(file);
}

/**************** Free the map and the collectible items array ****************/
void	ft_free_map(t_map *map)
{
	ft_free_array(map->map);
	free(map->items);
}

/************************ Prints the map in characters ************************/
void	ft_print_map(t_data data)
{
	int		i;
	t_map	map;

	map = data.map;
	ft_printf("\t ___________________________ \n");
	ft_printf("\t|                           |\n");
	ft_printf("\t|            MAP            |\n");
	ft_printf("\t|___________________________|\n\n");
	i = 0;
	while ((map.map)[i])
		ft_printf("\t%s\n", map.map[i++]);
	ft_printf("\n\tStart position: [%d, %d]\n", map.start.x, map.start.y);
	ft_printf("\n\tPlayer position: [%d, %d]\n", data.pos.x, data.pos.y);
	ft_printf("\tExit position: [%d, %d]\n", map.exit.x, map.exit.y);
	ft_printf("\tNumber of items to collect: %d\n", map.items_count);
	ft_printf("\tItems positions:\n");
	i = -1;
	while (++i < map.items_count)
		ft_printf("\t[%d, %d]\n", map.items[i].pos.x, map.items[i].pos.y);
	ft_printf("\tRIGHT: %d, LEFT: %d, UP: %d, DOWN: %d\n", data.inp.right,
		data.inp.left, data.inp.up, data.inp.down);
}

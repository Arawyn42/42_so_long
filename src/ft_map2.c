/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:21:30 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/28 17:57:34 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/******** Gets the start position on the map and set it in map struct *********/
void	ft_get_exit(t_map *map)
{
	int x;
	int y;

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
				break;
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
void	ft_print_map(t_map map)
{
	int	i;

	printf("\t ___________________________ \n");
	printf("\t|                           |\n");
	printf("\t|            MAP            |\n");
	printf("\t|___________________________|\n\n");
	i = 0;
	while ((map.map)[i])
		printf("\t%s\n", map.map[i++]);
	printf("\nStart position: [%d, %d]\n", map.start.x, map.start.y);
	printf("\tExit position: [%d, %d]\n", map.exit.x, map.exit.y);
	printf("\tNumber of collectibles : %d\n", map.items_count);
	printf("\tItems positions :\n");
	i = -1;
	while (++i < map.items_count)
		printf("\t[%d, %d]\n", map.items[i].pos.x, map.items[i].pos.y);
}

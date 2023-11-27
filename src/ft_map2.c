/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:21:30 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/27 23:28:29 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/************* Initializes a map with start values and item count *************/
void	ft_init_map(t_map *map, char *file)
{
	map->map = ft_get_map(file);
	map->start.x = -1;
	map->start.y = -1;
	ft_get_start(map);
	ft_set_items_pos(map);
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

	printf(" ___________________________ \n");
	printf("|                           |\n");
	printf("|            MAP            |\n");
	printf("|___________________________|\n\n");
	i = 0;
	while ((map.map)[i])
		printf("\t%s\n", map.map[i++]);
	printf("\nStart : [%d, %d]\n", map.start.x, map.start.y);
	printf("Number of collectibles : %d\n", map.items_count);
	printf("Items positions :\n");
	i = -1;
	while (++i < map.items_count)
		printf("[%d, %d]\n", map.items[i].pos.x, map.items[i].pos.y);
}

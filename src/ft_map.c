/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:52 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 11:50:28 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/************ Function to get the vertical size (height) of a map *************/
int	ft_get_map_height(char *file)
{
	char	*line;
	int		fd;
	int		size;

	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	size = 0;
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	return (size);
}

/*************** Counts the number of collectible items on a map **************/
int	ft_get_items_count(t_map *map)
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
			if (map->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/************ Gets and sets collectible items positions in the map ************/
void	ft_get_items_pos(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	map->items_count = ft_get_items_count(map);
	map->items = ft_calloc(map->items_count, sizeof(t_items));
	if (!map->items)
		return ;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'C')
			{
				map->items[count].pos.x = x;
				map->items[count].pos.y = y;
				count++;
			}
		}
	}
}

/********* Gets the map and returns it as a double array of characters ********/
char	**ft_get_map(char *file)
{
	int		fd;
	int		i;
	char	**map;
	int		height;

	fd = open(file, O_RDONLY, 0666);
	height = ft_get_map_height(file);
	map = ft_calloc(height + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[height] = NULL;
	get_next_line(-1);
	close(fd);
	return (map);
}

/******** Gets the start position on the map and set it in map struct *********/
void	ft_get_start(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->start.x = x;
				map->start.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

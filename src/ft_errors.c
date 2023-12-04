/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:52:48 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 16:41:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/******** Returns an error if there are more or less than 1 parameter *********/
int	ft_args_error(int ac)
{
	if (ac != 2)
	{
		ft_print_error("Error: Wrong number of arguments.\n");
		ft_print_error("Usage: ./so_long map.ber\n");
		return (0);
	}
	return (1);
}

/********************** Checks if the map is rectangular **********************/
int	ft_check_rect(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_print_error("Map error: The map must be rectangular.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/******** Returns an error if there are forbidden characters in a map *********/
int	ft_check_forbidden_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'M')
			{
				ft_print_error("Map error: The map must contains only");
				ft_print_error(" one of these characters:\n0 for an ");
				ft_print_error("empty space,\n1 for a wall,\nC for a ");
				ft_print_error("collectible item,\nM for an enemy,\n");
				ft_print_error("E for the exit,\nP for ");
				ft_print_error("the player's start position.\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/***************** Checks there are walls all around the map ******************/
static int	ft_check_walls2(char **map, int x, int y)
{
	while (x >= 0)
	{
		if (map[y][x] != '1')
			return (ft_print_error("Map error: The map must be \
surrounded by walls.\n"), 0);
		x--;
	}
	x++;
	while (y >= 0)
	{
		if (map[y][x] != '1')
			return (ft_print_error("Map error: The map must be \
surrounded by walls.\n"), 0);
		y--;
	}
	return (1);
}

/***************** Checks there are walls all around the map ******************/
int	ft_check_walls(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (ft_print_error("Map error: The map must be \
surrounded by walls.\n"), 0);
		x++;
	}
	x--;
	while (map[y])
	{
		if (map[y][x] != '1')
			return (ft_print_error("Map error: The map must be \
surrounded by walls.\n"), 0);
		y++;
	}
	y--;
	return (ft_check_walls2(map, x, y));
}

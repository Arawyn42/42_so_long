/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:31:58 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/22 20:44:28 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/****** Counts the number of exit, start position, and items, in a map ********/
static void	ft_map_EPC_cond(char c, int *exit, int *start, int *item)
{
	if (c == 'E')
		(*exit)++;
	if (c == 'C')
		(*item)++;
	if (c == 'P')
		(*start)++;
}

/**** Returns an error if a map dosen't contains 1 exit, 1 start position, *****/
/*********************** and at least 1 collectible item ***********************/
static int	ft_check_EPC(char **map)
{
	int	x;
	int	y;
	int	check[3];

	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_map_EPC_cond(map[y][x], &check[0], &check[1], &check[2]);
			x++;
		}
		y++;
	}
	if (check[0] != 1 || check[1] != 1 || check[2] < 1)
	{
		ft_print_error("Map error: The map must contains 1 exit, 1 start ");
		ft_print_error("position, and at least 1 collectible item.\n");
		return (0);
	}
	return (1);
}

/********************** Checks that there is no map error **********************/
int	ft_check_map(char *file)
{
	char	**map;

	map = ft_get_map(file);
	if (!ft_check_rect(map))
		return (ft_free_array(map), 0);
	if (!ft_check_forbidden_char(map))
		return (ft_free_array(map), 0);
	if (!ft_check_walls(map))
		return (ft_free_array(map), 0);
	if (!ft_check_EPC(map))
		return (ft_free_array(map), 0);
	ft_free_array(map);
	return (1);
}

/****** Replaces the right characters after checking if exit is reachable *****/
int	ft_replace_map(t_map map, int res)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'X')
				map.map[y][x] = '0';
			if (map.map[y][x] == 'Y')
				map.map[y][x] = 'C';
			x++;
		}
		y++;
	}
	map.map[map.start.y][map.start.x] = 'P';
	return (res);
}

/*********** Checks if the exit is reachable from the start position **********/
int	ft_check_exit_reachable(t_map map, int x, int y)
{
	if (x == -1 || y == -1)
		return (0);
	if (map.map[y][x] == 'E')
		return (ft_replace_map(map, 1));
	if (map.map[y][x] == 'P' || map.map[y][x] == '0' || map.map[y][x] == 'C')
	{
		if (map.map[y][x] == '0' || map.map[y][x] == 'P')
			map.map[y][x] = 'X';
		if (map.map[y][x] == 'C')
			map.map[y][x] = 'Y';
		if (ft_check_exit_reachable(map, x - 1, y) ||
			ft_check_exit_reachable(map, x + 1, y) ||
			ft_check_exit_reachable(map, x, y - 1) ||
			ft_check_exit_reachable(map, x, y + 1))
			return (1);
		if (map.map[y][x] == 'X')
			map.map[y][x] = '0';
		if (map.map[y][x] == 'Y')
			map.map[y][x] = 'C';
	}
	return (0);
}

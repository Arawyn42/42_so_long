/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:48 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/22 20:51:07 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*********** Checks if the exit is reachable from the start position **********/
int	ft_check_items_reachable(t_map map, int x, int y, t_items item)
{
	if (map.map[y][x] == 'C' && x == item.pos.x && y == item.pos.y)
		return (ft_replace_map(map, 1));
	if (map.map[y][x] == 'P' || map.map[y][x] == '0' || map.map[y][x] == 'C')
	{
		if (map.map[y][x] == '0' || map.map[y][x] == 'P')
			map.map[y][x] = 'X';
		if (map.map[y][x] == 'C' && (x != item.pos.x || y != item.pos.y))
			map.map[y][x] = 'Y';
		if (ft_check_items_reachable(map, x - 1, y, item) ||
			ft_check_items_reachable(map, x + 1, y, item) ||
			ft_check_items_reachable(map, x, y - 1, item) ||
			ft_check_items_reachable(map, x, y + 1, item))
			return (1);
		if (map.map[y][x] == 'Z')
			map.map[y][x] = 'P';
		if (map.map[y][x] == 'X')
			map.map[y][x] = '0';
		if (map.map[y][x] == 'Y')
			map.map[y][x] = 'C';
	}
	return (0);
}

/***** Checks if a map can be fully complete (exit and items reachables) ******/
int	ft_check_completable(t_map map, int x, int y)
{
	int	i;

	if (!ft_check_exit_reachable(map, x, y))
	{
		ft_print_error("Map error: The map can't be completed because ");
		ft_print_error("the exit is not reachable.\n");
		return (0);
	}
	i = 0;
	while (i < map.items_count)
	{
		if (!ft_check_items_reachable(map, x, y, map.items[i]))
		{
			ft_print_error("Map error: The map can't be completed because ");
			ft_print_error("some items are not reachable.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

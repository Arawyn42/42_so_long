/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:52:07 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/22 21:04:04 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	main(int ac, char **av)
{
	t_map	map;

	if (!ft_args_error(ac))
		return (1);
	if (!ft_check_map(av[1]))
		return (1);
	ft_init_map(&map, av[1]);
	if (!ft_check_completable(map, map.start.x, map.start.y))
		return (ft_print_map(map), ft_free_map(&map), 1);
	ft_print_map(map);
	ft_free_map(&map);
	return (0);
}

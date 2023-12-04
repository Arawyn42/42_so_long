/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:18:22 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 17:32:56 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void    ft_draw_map2(t_data *data, int *x, int *y)
{
    if (data->map.map[*y][*x] == '0')
        ft_print_img(data, &(data->ground), *x, *y);
    else if (data->map.map[*y][*x] == '1')
        ft_print_img(data, &(data->wall), *x, *y);
    else if (data->map.map[*y][*x] == 'C')
    {
        ft_init_img(data, &data->item, "./sprites/item1.xpm");
        ft_print_img(data, &(data->item), *x, *y);
    }
    else if (data->map.map[*y][*x] == 'D')
    {
        ft_init_img(data, &data->item, "./sprites/item3.xpm");
        ft_print_img(data, &(data->item), *x, *y);
    }
    else if (data->map.map[*y][*x] == 'E')
        ft_print_img(data, &(data->exit), *x, *y);
    else if (data->map.map[*y][*x] == 'M')
    {
        ft_init_img(data, &data->enemy, "./sprites/item1.xpm");
        ft_print_img(data, &(data->enemy), *x, *y);
    }
}

int ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map && data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			ft_draw_map2(data, &x, &y);
			x++;
		}
		y++;
	}
	ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	ft_draw_score(data);
    return (1);
}

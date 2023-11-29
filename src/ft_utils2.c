/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:36:55 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 00:29:54 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->ground.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->item.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(&data->map);
}

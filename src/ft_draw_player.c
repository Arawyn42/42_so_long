/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:48:52 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/29 23:07:04 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	ft_img_cpy(t_data *data, t_img img)
{
	t_img	cpy;

	cpy.img = mlx_xpm_file_to_image(data->mlx, img.path,
			&cpy.width, &cpy.height);
	cpy.addr = mlx_get_data_addr(cpy.img, &cpy.bpp,
			&cpy.line_length, &cpy.endian);
	return (cpy);
}

void	ft_draw_above(t_data *data, t_img img, int x, int y)
{
	int		i;
	int		j;
	t_img	cpy;
	int		cpy_clr;
	int		p_clr;

	cpy = ft_img_cpy(data, img);
	j = -1;
	while (++j < data->player.height)
	{
		i = -1;
		while (++i < data->player.width)
		{
			cpy_clr = j * cpy.line_length + i * (cpy.bpp / 8);
			p_clr = j * data->player.line_length + i * (data->player.bpp / 8);
			if (data->player.addr[p_clr])
			{
				cpy.addr[cpy_clr] = data->player.addr[p_clr];
				cpy.addr[cpy_clr + 1] = data->player.addr[p_clr + 1];
				cpy.addr[cpy_clr + 2] = data->player.addr[p_clr + 2];
			}
		}
	}
	ft_print_img(data, &cpy, x, y);
	mlx_destroy_image(data->mlx, cpy.img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:48:52 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 13:16:50 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	ft_img_cpy(t_data *data, t_img img)
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

void	ft_draw_score(t_data *data)
{
	int		x;
	int		y;
	char	*score;

	y = 20;
	while (y < 50)
	{
		x = 10;
		while (x < 55)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, 0x00ffffff);
			x++;
		}
		y++;
	}
	score = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->window, 15, 32, 0x00000000, "Moves: ");
	if (ft_strlen(score) == 1)
		mlx_string_put(data->mlx, data->window, 29, 46, 0x00006400, score);
	else if (ft_strlen(score) == 2)
		mlx_string_put(data->mlx, data->window, 25, 46, 0x00006400, score);
	else
		mlx_string_put(data->mlx, data->window, 20, 46, 0x00006400, score);
	free(score);
}

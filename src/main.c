/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:52:07 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/27 23:47:28 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	char	*dest;

	dest = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}


void	ft_print_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img->img,
											x * img->width, y * img->height);
}

void	ft_init_img(t_data *data, t_img *img)
{
	img->width = 64;
	img->height = 64;
	img->img = mlx_xpm_file_to_image(data->mlx, img->path,
												&(img->width), &(img->height));
	// img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
	// 										&(img->line_length), &(img->endian));
}

void	ft_init_imgs(t_data *data)
{
	data->ground.path = "./sprites/ground.xpm";
	data->wall.path = "./sprites/wall.xpm";
	data->exit.path = "./sprites/exit.xpm";
	data->item1.path = "./sprites/item1.xpm";
	data->item2.path = "./sprites/item2.xpm";
	data->item3.path = "./sprites/item3.xpm";
	ft_init_img(data, &data->ground);
	ft_init_img(data, &data->wall);
	ft_init_img(data, &data->exit);
	ft_init_img(data, &data->item1);
}

int ft_refresh(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '0')
				ft_print_img(data, &data->ground, x, y);
			else if (data->map.map[y][x] == '1')
				ft_print_img(data, &data->wall, x, y);
			else if (data->map.map[y][x] == 'C')
				ft_print_img(data, &data->item1, x, y);
			else if (data->map.map[y][x] == 'E')
				ft_print_img(data, &data->exit, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_create_window(t_data *data, int w, int h)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, w, h, "The best game ever");
	if (!data->window)
		return (free(data->mlx));
	ft_init_imgs(data);
	mlx_loop_hook(data->mlx, &ft_refresh, data);
	mlx_loop(data->mlx);
}

void	ft_free_mlx()
{
	return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_check_all_errors(ac, av, &data))
		return (exit(EXIT_FAILURE), 1);
	ft_create_window(&data, data.map.width * 64, data.map.height * 64);
	ft_free_map(&data.map);
	return (0);
}

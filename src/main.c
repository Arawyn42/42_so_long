/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:52:07 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/29 00:54:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_draw_above(t_data *data, t_img img, int x, int y);

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

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	char	*dest;

	dest = img.addr + (y * img.line_length + x * (img.bpp / 8));
	*(unsigned int *)dest = color;
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
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
											&(img->line_length), &(img->endian));
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
				ft_print_img(data, &(data->ground), x, y);
			else if (data->map.map[y][x] == '1')
				ft_print_img(data, &(data->wall), x, y);
			else if (data->map.map[y][x] == 'C')
				ft_print_img(data, &(data->item), x, y);
			else if (data->map.map[y][x] == 'E')
				ft_print_img(data, &(data->exit), x, y);
			x++;
		}
		y++;
	}
	return (1);
}

t_img    ft_img_cpy(t_data *data, t_img img)
{
	t_img	cpy;

    cpy.img = mlx_xpm_file_to_image(data->mlx, img.path,
											&cpy.width, &cpy.height);
	cpy.addr = mlx_get_data_addr(cpy.img, &cpy.bpp,
									&cpy.line_length, &cpy.endian);
	ft_printf("%s\n", img.path);
    return (cpy);
}

void    ft_draw_above(t_data *data, t_img img, int x, int y)
{
	int		i;
	int		j;
	t_img	cpy;
	int cpy_clr;
	int	p_clr;

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

void	ft_init_imgs(t_data *data)
{
	data->ground.path = "./sprites/ground.xpm";
	data->player.path = "./sprites/player_bot1.xpm";
	data->wall.path = "./sprites/wall.xpm";
	data->exit.path = "./sprites/exit.xpm";
	data->item.path = "./sprites/item1.xpm";
	ft_init_img(data, &(data->ground));
	ft_init_img(data, &(data->player));
	ft_init_img(data, &(data->wall));
	ft_init_img(data, &(data->exit));
	ft_init_img(data, &(data->item));
}

void	ft_right(t_data *data)
{
	data->player.path = "./sprites/player_bot1.xpm";
	if (data->map.map[data->pos.y][data->pos.x + 1] == '0')
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		data->map.map[data->pos.y][data->pos.x ] = '0';
		data->pos.x += 1;
		data->map.map[data->pos.y][data->pos.x ] = 'P';
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_left(t_data *data)
{
	data->player.path = "./sprites/player_bot1.xpm";
	if (data->map.map[data->pos.y][data->pos.x - 1] == '0')
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		data->map.map[data->pos.y][data->pos.x ] = '0';
		data->pos.x -= 1;
		data->map.map[data->pos.y][data->pos.x ] = 'P';
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_up(t_data *data)
{
	data->player.path = "./sprites/player_bot1.xpm";
	if (data->map.map[data->pos.y - 1][data->pos.x] == '0')
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		data->map.map[data->pos.y][data->pos.x ] = '0';
		data->pos.y -= 1;
		data->map.map[data->pos.y][data->pos.x ] = 'P';
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

void	ft_down(t_data *data)
{
	data->player.path = "./sprites/player_bot1.xpm";
	if (data->map.map[data->pos.y + 1][data->pos.x] == '0')
	{
		ft_print_img(data, &data->ground, data->pos.x, data->pos.y);
		data->map.map[data->pos.y][data->pos.x] = '0';
		data->pos.y += 1;
		data->map.map[data->pos.y][data->pos.x] = 'P';
		ft_draw_above(data, data->ground, data->pos.x, data->pos.y);
	}
}

int	ft_key_pressed(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_free_mlx(data);
		exit(EXIT_SUCCESS);
	}
	if (key == XK_Right || key == XK_d)
		ft_right(data);
	if (key == XK_Left || key == XK_a)
		ft_left(data);
	if (key == XK_Up || key == XK_w)
		ft_up(data);
	if (key == XK_Down || key == XK_s)
		ft_down(data);
	ft_print_map(data->map); // DEBUG
	return (0);
}

void	ft_create_window(t_data *data, int w, int h)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, w, h, "The best game ever");
	if (!data->window)
		return (free(data->mlx));
	ft_init_imgs(data);
	mlx_loop_hook(data->mlx, &ft_refresh, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, &ft_key_pressed, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_check_all_errors(ac, av, &data))
		return (exit(EXIT_FAILURE), 1);
	ft_create_window(&data, data.map.width * 64, data.map.height * 64);
	return (0);
}

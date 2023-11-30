/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:52:07 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/30 19:37:59 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_refresh(t_data *data)
{
	data->clock++;
	if (data->clock >= 50000)
		data->clock = 0;
	if (data->inp.right && !data->inp.left && !data->inp.up && !data->inp.down)
		ft_right(data);
	if (data->inp.left && !data->inp.right && !data->inp.up && !data->inp.down)
		ft_left(data);
	if (data->inp.up && !data->inp.right && !data->inp.left && !data->inp.down)
		ft_up(data);
	if (data->inp.down && !data->inp.right && !data->inp.left && !data->inp.up)
		ft_down(data);
	return (1);
}

static void	ft_key_pressed2(int key, t_data *data)
{
	if ((key == XK_Up || key == XK_w) && !data->inp.right
		&& !data->inp.left && !data->inp.up && !data->inp.down)
	{
		data->clock = 0;
		data->inp.up = 1;
	}
	else if ((key == XK_Down || key == XK_s) && !data->inp.right
		&& !data->inp.left && !data->inp.up && !data->inp.down)
	{
		data->clock = 0;
		data->inp.down = 1;
	}
}

int	ft_key_pressed(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_free_mlx(data);
		exit(EXIT_SUCCESS);
	}
	else if ((key == XK_Right || key == XK_d) && !data->inp.right
		&& !data->inp.left && !data->inp.up && !data->inp.down)
	{
		data->clock = 0;
		data->inp.right = 1;
		data->inp.anim = 1;
	}
	else if ((key == XK_Left || key == XK_a) && !data->inp.right
		&& !data->inp.left && !data->inp.up && !data->inp.down)
	{
		data->clock = 0;
		data->inp.left = 1;
		data-
	}
	else
		ft_key_pressed2(key, data);
	ft_print_map(*data); // DEBUG
	return (0);
}

static void	ft_create_window(t_data *data, int w, int h)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, w, h, "The best game ever");
	if (!data->window)
		return (free(data->mlx));
	ft_init_imgs(data);
	ft_init_inputs(data);
	ft_draw_map(data);
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

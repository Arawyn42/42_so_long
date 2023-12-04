/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:50:43 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 20:22:00 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_refresh(t_data *data)
{
	data->clock++;
	if (data->clock >= 50000)
		data->clock = 0;
	data->clock2++;
	if (data->clock2 >= 50000)
		data->clock2 = 0;
	ft_enemies_anim(data);
	if (data->inp.right && !data->inp.left && !data->inp.up && !data->inp.down)
		ft_right(data);
	if (data->inp.left && !data->inp.right && !data->inp.up && !data->inp.down)
		ft_left(data);
	if (data->inp.up && !data->inp.right && !data->inp.left && !data->inp.down)
		ft_up(data);
	if (data->inp.down && !data->inp.right && !data->inp.left && !data->inp.up)
		ft_down(data);
	if (data->inp.win == 1)
		ft_win_game(data);
	else if (data->inp.win == 2 && data->inp.anim == 3)
		ft_enemies_end_anim(data);
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
		ft_close(data);
	else if ((key == XK_Right || key == XK_d) && !data->inp.right
		&& !data->inp.left && !data->inp.up && !data->inp.down)
	{
		data->clock = 0;
		data->inp.right = 1;
	}
	else if ((key == XK_Left || key == XK_a) && !data->inp.right
		&& !data->inp.left && !data->inp.up && !data->inp.down)
	{
		data->clock = 0;
		data->inp.left = 1;
	}
	else
		ft_key_pressed2(key, data);
	if (key == XK_space)
		ft_print_infos(*data);
	return (0);
}

void	ft_create_window(t_data *data, int w, int h)
{
	data->mlx = mlx_init();
	if (data->mlx)
	{
		data->window = mlx_new_window(data->mlx, w, h, "The best game ever");
		if (!data->window)
			return (free(data->mlx));
		ft_init_imgs(data);
		ft_init_inputs(data);
		ft_draw_map(data);
		mlx_loop_hook(data->mlx, &ft_refresh, data);
		mlx_hook(data->window, KeyPress, KeyPressMask, &ft_key_pressed, data);
		mlx_hook(data->window, DestroyNotify, NoEventMask, &ft_close, data);
		mlx_hook(data->window, ResizeRequest, ResizeRedirectMask,
			&ft_draw_map, data);
		mlx_loop(data->mlx);
	}
	else
		return (ft_print_error("Error: mlx_ptr didn't init correctly."));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:52:07 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/04 20:21:00 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_check_all_errors(ac, av, &data))
		return (exit(EXIT_FAILURE), 1);
	ft_create_window(&data, data.map.width * 64, data.map.height * 64);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:03:14 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 13:00:41 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 0)
	{
		n = n / 10;
		i++;
		if (n == 0)
			break ;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		len;

	nb = (long) n;
	len = ft_len(nb);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = 0;
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	while (nb >= 0)
	{
		res[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
		if (nb == 0)
			break ;
	}
	return (res);
}

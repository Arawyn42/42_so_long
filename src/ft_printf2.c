/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:05:19 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/28 22:56:27 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* %p : Prints a void * pointer in hexadecimal format and returns the size */
void	ft_pointer(unsigned long ptr, int *size)
{
	if (!ptr)
		(*size) += ft_putstr("(nil)");
	else
	{
		(*size) += ft_putstr("0x");
		ft_puthexnbr(ptr, size, "0123456789abcdef");
	}
}

/* %d or %i : Prints a decimal number in base 10 */
void	ft_putnbr(int n, int *size)
{
	long	nb;

	nb = (long) n;
	if (nb < 0)
	{
		nb = -nb;
		(*size) += ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, size);
	(*size) += ft_putchar(nb % 10 + '0');
}

/* %u : Prints an unsigned decimal number in base 10 */
void	ft_putunbr(unsigned int n, int *size)
{
	if (n > 9)
		ft_putunbr(n / 10, size);
	(*size) += ft_putchar(n % 10 + '0');
}

/* %x or %X : Prints a number in hexadecimal lowercase or uppercase format */
void	ft_puthexnbr(unsigned long n, int *size, char *base)
{
	if (n >= 16)
		ft_puthexnbr(n / 16, size, base);
	(*size) += ft_putchar(base[n % 16]);
}

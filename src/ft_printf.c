/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:36:13 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/28 22:56:16 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Prints one character */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* Prints a string of characters and returns the size of the string */
int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

/* Handle the different possible format */
static int	ft_format(va_list args, char c)
{
	int		size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_pointer(va_arg(args, unsigned long), &size);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &size);
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), &size);
	else if (c == 'x')
		ft_puthexnbr(va_arg(args, unsigned int), &size, "0123456789abcdef");
	else if (c == 'X')
		ft_puthexnbr(va_arg(args, unsigned int), &size, "0123456789ABCDEF");
	else if (c == '%')
		size += ft_putchar('%');
	return (size);
}

/* Main function */
int	ft_printf(const char *input, ...)
{
	int		i;
	int		size;
	va_list	args;

	va_start(args, input);
	i = 0;
	size = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			++i;
			size += ft_format(args, input[i]);
		}
		else
			size += ft_putchar(input[i]);
		++i;
	}
	va_end(args);
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:46:16 by drenassi          #+#    #+#             */
/*   Updated: 2023/12/02 11:50:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/******************* Counts the number of chars in a string *******************/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*********************** Initializes a memory space to 0 **********************/
static void	ft_bzero(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = '\0';
		i++;
	}
}

/************************ Allocates memory on n bytes *************************/
void	*ft_calloc(size_t n, size_t size)
{
	void	*pointer;

	if (size != 0 && n * size / size != n)
		return (NULL);
	pointer = malloc(n * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, n * size);
	return (pointer);
}

/********** Prints an error message on the standard error output (2) **********/
void	ft_print_error(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(STDERR_FILENO, &str[i++], 1);
}

/********************* Frees a double array of characters *********************/
void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

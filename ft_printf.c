/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:58:24 by nikitadorof       #+#    #+#             */
/*   Updated: 2025/01/13 19:10:00 by ndorofey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_selector(va_list args, char word)

{
	int	i;

	i = 0;
	if (word == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (word == 'u')
		i += ft_putunsnbr(va_arg(args, unsigned int));
	else if (word == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (word == 'd' || word == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (word == 'x' || word == 'X')
		i += ft_puthexa(va_arg(args, unsigned int), word);
	else if (word == 'p')
	{
		i += ft_putstr("0x");
		if (i < 0)
			return (-1);
		i += ft_putvoid(va_arg(args, unsigned long));
	}
	else if (word == '%')
		i += ft_putchar(('%'));
	else
		i += ft_putchar(word);
	return (i);
}

int	ft_printf(char const *place, ...)
{
	int		size;
	int		i;
	va_list	args;

	size = 0;
	i = 0;
	va_start(args, place);
	while (place[i])
	{
		if (place[i] == '%')
		{
			size += ft_selector(args, place[i + 1]);
			i++;
		}
		else
			size += ft_putchar(place[i]);
		if (size < 0)
			return (-1);
		i++;
	}
	va_end (args);
	return (size);
}

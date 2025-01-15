/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:58:24 by nikitadorof       #+#    #+#             */
/*   Updated: 2025/01/15 15:32:37 by ndorofey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_args(const char *format, va_list args, int count);
static int	ft_selector(va_list args, char word);

static int	easter_egg_2(unsigned long hexa)
{
	int				i;

	i = 0;
	if (hexa == 0)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	if (i < 0)
		return (-1);
	i += ft_putvoid(hexa);
	return (i);
}

static int	ft_selector(va_list args, char word)
{
	int				i;

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
		i += easter_egg_2(va_arg(args, unsigned long));
	else if (word == '%')
		i += ft_putchar('%');
	else
		i += ft_putchar(word);
	return (i);
}

static int	ft_process_args(const char *format, va_list args, int count)
{
	int		control;
	int		i;

	control = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			control = ft_selector(args, format[i + 1]);
			if (control == -1)
				return (control);
			count += control;
			i += 2;
		}
		else
		{
			(count += ft_putchar(format[i]));
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				count;

	count = 0;
	if (!format || format[0] == '\0')
		return (-1);
	va_start(args, format);
	count = ft_process_args(format, args, count);
	va_end(args);
	return (count);
}

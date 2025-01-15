/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:57:44 by nikitadorof       #+#    #+#             */
/*   Updated: 2025/01/14 22:33:35 by ndorofey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countuns(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static int	easter_egg(int nbr)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	return (0);
}

int	ft_putnbr(int nbr)
{
	int	count;
	int	temp;

	count = 0;
	if (nbr == 0 || nbr == INT_MIN)
		return (easter_egg(nbr));
	if (nbr < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		nbr *= -1;
		count++;
	}
	if (nbr >= 10)
	{
		temp = ft_putnbr(nbr / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	if (ft_putchar(nbr % 10 + '0') < 0)
		return (-1);
	return (count + 1);
}

int	ft_putunsnbr(unsigned int nbr)
{
	int	count;

	count = ft_countuns(nbr);
	if (nbr == 0)
		return (ft_putstr("0"));
	if (nbr > 9 && ft_putunsnbr(nbr / 10) < 0)
		return (-1);
	if (ft_putchar(nbr % 10 + '0') < 0)
		return (-1);
	return (count);
}

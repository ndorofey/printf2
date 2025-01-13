/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:15:55 by nikitadorof       #+#    #+#             */
/*   Updated: 2025/01/13 19:20:59 by ndorofey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counteruns(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

static int	ft_counterlong(unsigned long nbr)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

int	ft_puthexa(unsigned int nbr, char word)
{
	char	*hexa;
	int		count;

	count = ft_counteruns(nbr);
	if (word == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nbr == 0)
		return (ft_putchar ('0'));
	if (nbr > 15 && ft_puthexa(nbr / 16, word) < 0)
		return (-1);
	if (!ft_putchar(hexa[nbr % 16]))
		return (-1);
	/*if (word == 'x' && ft_putchar(hexa[nbr % 16]) < 0)
		return (-1);
	else if (word == 'X' && ft_putchar(hexas[nbr % 16] < 0))
		return (-1);*/
	return (count);
}

int	ft_putvoid(unsigned long nbr)
{
	char	*hexa;
	int		count;

	count = ft_counterlong(nbr);
	hexa = "0123456789abcdef";
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr > 15 && ft_putvoid(nbr / 16) < 0)
		return (-1);
	if (ft_putchar(hexa[nbr % 16]) < 0)
		return (-1);
	return (count);
}

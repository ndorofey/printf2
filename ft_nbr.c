/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:57:44 by nikitadorof       #+#    #+#             */
/*   Updated: 2025/01/13 21:08:44 by ndorofey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
/*
static int	ft_count(int nbr)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	printf("count %d\n", count);
	return (count);
}
*/
static int	ft_count(int nbr)
{
	int count;

	count = 0;
	if (nbr > 9)
	{
		count = ft_count(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		count ++;
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	int count;
	int count1;
	long n;

	n = nbr;
	count1 = 0;
	count = 0;
	if (n < -2147483648)
		count = ft_putstr("2147483648");
	if (nbr < 0)
	{
		//count = ft_putchar('-');
		write(1, "-", 1);
		nbr = -nbr;
		count1 ++;
		if (nbr == -2147483648)
			count = ft_putstr("2147483648");
	}
	if (nbr > 0)
		count = ft_count(nbr);
	/*
	if (nbr > 9)
	{
		count = ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		count ++;
	}*/
	count = count1 + count;
	return (count);

}

/*
int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		if (write(1, "-2", 2) < 0)
			return (-1);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		nbr *= -1;
		count++;
	}
	count += ft_count(nbr);
	if (nbr < 10 && ft_putchar(nbr + 48) < 0)
		return (-1);
	else if (nbr > 9 && ft_putnbr(nbr / 10) < 0)
		return (-1);
	if (ft_putnbr(nbr % 10) < 0)
		return (-1);
	return (count);
}*/

int	ft_putunsnbr(unsigned int nbr)
{
	int	count;

	count = ft_countuns(nbr);
	if (nbr > 9 && ft_putunsnbr(nbr / 10) < 0)
		return (-1);
	if (ft_putchar(nbr % 10 + '0') < 0)
		return (-1);
	return (count);
}

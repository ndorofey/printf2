/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndorofey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:44:27 by ndorofey          #+#    #+#             */
/*   Updated: 2025/01/13 21:23:27 by ndorofey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	/*char c = 'j';
	ft_printf("%%c\n", c);
	printf("%%c\n", c);*/
	ft_printf("noOriginal %d\n", ft_printf("number: %d\ncharacter: %c\n, %u\n, %x\n", -2147483648, 'A', 255, 255));
	printf("siOriginal %d\n", printf("number: %d\ncharacter: %c\n, %u\n, %x\n", -2147483648, 'A', 255, 255));

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:40 by surpetro          #+#    #+#             */
/*   Updated: 2024/02/16 15:18:09 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_p(unsigned long n)
{
	char	*str;
	size_t	count;

	count = 0;
	str = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(str[n]);
		count++;
	}
	else
	{
		count += ft_p(n / 16);
		count += ft_p(n % 16);
	}
	return (count);
}

unsigned int	ft_hexd(unsigned long n, char s)
{
	char	*str;
	size_t	count;

	count = 0;
	if (s == 'p')
	{
		count += ft_putstr("0x");
		count += ft_p(n);
		return (count);
	}
	if (s != 'x' && s != 'X')
		return (0);
	str = "0123456789abcdef";
	if (s == 'X')
		str = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(str[n]);
	else
	{
		count += ft_hexd(n / 16, s);
		count += ft_hexd(n % 16, s);
	}
	return (count);
}

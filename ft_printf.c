/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:25:35 by surpetro          #+#    #+#             */
/*   Updated: 2024/02/16 15:19:59 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			res += ft_determinant(args, s[i]);
		}
		else
		{
			res += ft_putchar(s[i]);
		}
		++i;
	}
	return (res);
}

int	ft_determinant(va_list a, const char x)
{
	int	length;

	length = 0;
	if (x == '%')
		length += ft_putchar('%');
	if (x == 'c')
		length += ft_putchar(va_arg(a, int));
	if (x == 's')
		length += ft_putstr(va_arg(a, const char *));
	if (x == 'd' || x == 'i')
		length += ft_putnbr(va_arg(a, unsigned int));
	if (x == 'u')
		length += ft_putunit(va_arg(a, unsigned int));
	if (x == 'p' || x == 'x' || x == 'X')
	{
		if (x == 'p')
			length += ft_hexd(va_arg(a, unsigned long), x);
		else
			length += ft_hexd(va_arg(a, unsigned int), x);
	}
	return (length);
}
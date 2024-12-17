/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:30:46 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/15 16:20:11 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(long n_l)
{
	int	count;

	count = 0;
	if (n_l < 0)
	{
		count++;
		n_l *= -1;
	}
	while (n_l != 0)
	{
		count++;
		n_l /= 10;
	}
	return (count);
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		++i;
	}
	return (i);
}

unsigned int	ft_putnbr(int n)
{
	int	length;

	length = len(n);
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (length);
}

int	ft_putunit(unsigned int n)
{
	int	length;

	length = len(n);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n > 9)
	{
		ft_putunit(n / 10);
		ft_putunit(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (length);
}

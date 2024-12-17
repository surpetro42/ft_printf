/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:01:39 by surpetro          #+#    #+#             */
/*   Updated: 2024/02/27 13:07:41 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int				ft_printf(const char *s, ...);
int				ft_putchar(int c);
int				ft_determinant(va_list a, const char x);
int				ft_putstr(const char *s);
unsigned int	ft_putnbr(int n);
unsigned int	ft_hexd(unsigned long n, char x);
int				ft_putunit(unsigned int u);

#endif

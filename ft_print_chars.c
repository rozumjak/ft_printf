/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrozumek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:34:53 by jrozumek          #+#    #+#             */
/*   Updated: 2023/11/22 21:26:15 by jrozumek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	print_string(char *str, int *count)
{
	if (str == NULL)
	{
		print_string("(null)", count);
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		(*count)++;
		str++;
	}
}

void	print_digit(long nbr, int base, int *count, char c)
{
	char	*digits;

	if (c == 'X')
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		(*count)++;
		print_digit(-nbr, base, count, c);
	}
	else if (nbr < base)
	{
		write(1, &digits[nbr], 1);
		(*count)++;
	}
	else
	{
		print_digit(nbr / base, base, count, c);
		write(1, &digits[nbr % base], 1);
		(*count)++;
	}
}

void	print_pointer(size_t nbr, int *count)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (nbr == 0)
	{
		print_string("(nil)", count);
		return ;
	}
	if (nbr < 16)
	{
		print_string("0x", count);
		write(1, &digits[nbr], 1);
		(*count)++;
	}
	else
	{
		print_pointer(nbr / 16, count);
		write(1, &digits[nbr % 16], 1);
		(*count)++;
	}
}

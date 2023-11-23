/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrozumek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:23:02 by jrozumek          #+#    #+#             */
/*   Updated: 2023/11/22 21:23:06 by jrozumek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, string);
	count = 0;
	while (*string)
	{
		if (*string == '%')
			print_format(*(++string), ap, &count);
		else
			count += write(1, string, 1);
		string++;
	}
	va_end(ap);
	return (count);
}

void	print_format(char c, va_list ap, int *count)
{
	if (c == 'c')
		print_char(va_arg(ap, int), count);
	else if (c == 's')
		print_string(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		print_digit(va_arg(ap, int), 10, count, 'i');
	else if (c == 'u')
		print_digit(va_arg(ap, unsigned int), 10, count, 'u');
	else if (c == 'x')
		print_digit(va_arg(ap, unsigned int), 16, count, 'x');
	else if (c == 'X')
		print_digit(va_arg(ap, unsigned int), 16, count, 'X');
	else if (c == 'p')
		print_pointer(va_arg(ap, size_t), count);
	else if (c == '%')
		print_char('%', count);
	else
		print_char(c, count);
}

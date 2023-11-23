/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrozumek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:09:25 by jrozumek          #+#    #+#             */
/*   Updated: 2023/11/22 20:17:11 by jrozumek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *string, ...);
void	print_format(char c, va_list ap, int *count);
void	print_char(int c, int *count);
void	print_string(char *str, int *count);
void	print_digit(long nbr, int base, int *count, char c);
void	print_pointer(size_t nbr, int *count);

#endif

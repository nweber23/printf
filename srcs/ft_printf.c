/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:37:57 by nweber            #+#    #+#             */
/*   Updated: 2025/07/07 18:05:01 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	format_handler(const char *frmt, int i, va_list args)
{
	if (frmt[i] == 'd' || frmt[i] == 'i')
		return (putnbr(va_arg(args, int)));
	else if (frmt[i] == 'c')
		return (ft_putchar(va_arg(args, char)));
	else if (frmt[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (frmt[i] == 'u')
		return (putnbr_unsigned(va_arg(args, int)));
	else if (frmt[i] == 'x')
		return (convert_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (frmt[i] == 'X')
		return (convert_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (frmt[i] == 'p')
		return (convert_pointer(va_arg(args, void *)));
	else if (frmt[i] == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

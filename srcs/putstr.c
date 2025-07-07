/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:59:59 by nweber            #+#    #+#             */
/*   Updated: 2025/07/07 18:14:17 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (ft_putchar(str[len]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

static int convert_hex_pointer(unsigned long n, char *charset)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len = convert_hex_pointer(n / 16, charset);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar(charset[n % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	convert_pointer(void *p)
{
	unsigned long	addr;
	int				len;

	len = 0;
	addr = (unsigned long)p;
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	if (addr == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (len + 1);
	}
	len += convert_hex_pointer(addr, "0123456789abcdef");
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:58:38 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:58:41 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	digit_count(unsigned long n, int base)
{
	int	count;

	count = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*get_digits(unsigned long n, int base, int upper)
{
	char		*charset;
	char		*str;
	int			len;

	if (upper)
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	len = digit_count(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = charset[n % base];
		n /= base;
	}
	return (str);
}

char	*pad_precision(char *digits, t_format *f)
{
	int		len;
	int		pad;
	char	*padded;

	if (!f->has_precision)
		return (digits);
	if (f->precision == 0 && ft_strncmp(digits, "0", 2) == 0)
	{
		digits[0] = '\0';
		return (digits);
	}
	len = ft_strlen(digits);
	pad = f->precision - len;
	if (pad <= 0)
		return (digits);
	padded = malloc(len + pad + 1);
	if (!padded)
		return (digits);
	ft_memset(padded, '0', pad);
	ft_strlcpy(padded + pad, digits, len + 1);
	free(digits);
	return (padded);
}

char	*get_sign_prefix(t_format *f, int negative)
{
	if (negative)
		return (ft_strdup("-"));
	if (f->plus)
		return (ft_strdup("+"));
	if (f->space)
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

char	*get_hash_prefix(t_format *f, unsigned long value)
{
	if (!f->hash || value == 0 || (f->conv != 'x' && f->conv != 'X'))
		return (ft_strdup(""));
	if (f->conv == 'X')
		return (ft_strdup("0X"));
	return (ft_strdup("0x"));
}

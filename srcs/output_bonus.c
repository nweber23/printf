/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:58:45 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:58:47 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	write_repeat(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		i++;
	}
	return (n);
}

static int	write_str(const char *s)
{
	int	len;

	len = ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

int	output_padded(t_format *f, const char *prefix,
		const char *digits, int is_numeric)
{
	int	core_len;
	int	pad;
	int	zero_pad;

	core_len = ft_strlen(prefix) + ft_strlen(digits);
	pad = f->width - core_len;
	if (pad < 0)
		pad = 0;
	zero_pad = is_numeric && f->zero && !f->minus && !f->has_precision;
	if (f->minus)
		return (write_str(prefix) + write_str(digits) + write_repeat(' ', pad));
	if (zero_pad)
		return (write_str(prefix) + write_repeat('0', pad) + write_str(digits));
	return (write_repeat(' ', pad) + write_str(prefix) + write_str(digits));
}

int	output_char(t_format *f, char c)
{
	int	pad;

	pad = f->width - 1;
	if (pad < 0)
		pad = 0;
	if (f->minus)
		return (write(1, &c, 1) + write_repeat(' ', pad));
	return (write_repeat(' ', pad) + write(1, &c, 1));
}

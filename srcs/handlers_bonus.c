/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:59:02 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:59:03 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	handle_int(t_format *f, va_list args)
{
	long	value;
	long	abs_value;
	char	*digits;
	char	*prefix;
	int		ret;

	value = va_arg(args, int);
	abs_value = value;
	if (abs_value < 0)
		abs_value = -abs_value;
	digits = pad_precision(get_digits(abs_value, 10, 0), f);
	prefix = get_sign_prefix(f, value < 0);
	ret = output_padded(f, prefix, digits, 1);
	free(digits);
	free(prefix);
	return (ret);
}

int	handle_uint(t_format *f, va_list args, int base, int upper)
{
	unsigned long	value;
	char			*digits;
	char			*prefix;
	int				ret;

	value = va_arg(args, unsigned int);
	digits = pad_precision(get_digits(value, base, upper), f);
	prefix = get_hash_prefix(f, value);
	ret = output_padded(f, prefix, digits, 1);
	free(digits);
	free(prefix);
	return (ret);
}

int	handle_str(t_format *f, va_list args)
{
	char	*s;
	char	*digits;
	int		ret;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	if (f->has_precision)
		digits = ft_substr(s, 0, f->precision);
	else
		digits = ft_strdup(s);
	ret = output_padded(f, "", digits, 0);
	free(digits);
	return (ret);
}

int	handle_char(t_format *f, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (output_char(f, c));
}

int	handle_ptr(t_format *f, va_list args)
{
	void	*p;
	char	*digits;
	char	*sign;
	char	*prefix;
	int		ret;

	p = va_arg(args, void *);
	if (!p)
		return (output_padded(f, "", NULL_PTR, 0));
	digits = pad_precision(get_digits((unsigned long)p, 16, 0), f);
	sign = get_sign_prefix(f, 0);
	prefix = ft_strjoin(sign, "0x");
	ret = output_padded(f, prefix, digits, 1);
	free(digits);
	free(sign);
	free(prefix);
	return (ret);
}

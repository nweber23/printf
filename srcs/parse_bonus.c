/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:58:31 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:58:34 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	set_flag(t_format *f, char c)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '+')
		f->plus = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '#')
		f->hash = 1;
	else
		return (0);
	return (1);
}

static void	parse_flags(const char *frmt, int *i, t_format *f)
{
	while (frmt[*i] && set_flag(f, frmt[*i]))
		(*i)++;
}

static void	parse_width(const char *frmt, int *i, t_format *f)
{
	f->width = 0;
	while (ft_isdigit(frmt[*i]))
	{
		f->width = f->width * 10 + (frmt[*i] - '0');
		(*i)++;
	}
}

static void	parse_precision(const char *frmt, int *i, t_format *f)
{
	if (frmt[*i] != '.')
		return ;
	(*i)++;
	f->has_precision = 1;
	f->precision = 0;
	while (ft_isdigit(frmt[*i]))
	{
		f->precision = f->precision * 10 + (frmt[*i] - '0');
		(*i)++;
	}
}

int	parse_format(const char *frmt, int *i, t_format *f)
{
	f->minus = 0;
	f->zero = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->has_precision = 0;
	parse_flags(frmt, i, f);
	parse_width(frmt, i, f);
	parse_precision(frmt, i, f);
	f->conv = frmt[*i];
	if (!ft_strchr("cspdiuxX%", f->conv))
		return (0);
	return (1);
}

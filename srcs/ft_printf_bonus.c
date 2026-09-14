/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:59:12 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:59:15 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	handle_percent(const char *frmt, int *i, va_list args)
{
	t_format	f;

	if (!parse_format(frmt, i, &f))
		return (0);
	return (dispatch_conversion(&f, args));
}

static int	print_loop_bonus(const char *frmt, va_list args)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			i++;
			ret = handle_percent(frmt, &i, args);
			if (ret == -1)
				return (-1);
			count += ret;
		}
		else
		{
			if (write(1, &frmt[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		count;

	va_start(args, frmt);
	count = print_loop_bonus(frmt, args);
	va_end(args);
	return (count);
}

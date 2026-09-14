/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:59:19 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:59:23 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	dispatch_conversion(t_format *f, va_list args)
{
	if (f->conv == 'd' || f->conv == 'i')
		return (handle_int(f, args));
	else if (f->conv == 'u')
		return (handle_uint(f, args, 10, 0));
	else if (f->conv == 'x')
		return (handle_uint(f, args, 16, 0));
	else if (f->conv == 'X')
		return (handle_uint(f, args, 16, 1));
	else if (f->conv == 's')
		return (handle_str(f, args));
	else if (f->conv == 'c')
		return (handle_char(f, args));
	else if (f->conv == 'p')
		return (handle_ptr(f, args));
	else if (f->conv == '%')
		return (write(1, "%", 1));
	return (0);
}

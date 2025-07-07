/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:21:59 by nweber            #+#    #+#             */
/*   Updated: 2025/07/07 17:23:35 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	convert_hex(unsigned int n, char *charset);
int	putnbr_unsigned(unsigned int n);
int	putnbr(int n);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:57:57 by nweber            #+#    #+#             */
/*   Updated: 2026/09/14 11:58:15 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		precision;
	int		has_precision;
	char	conv;
}	t_format;

// parse_bonus.c
int		parse_format(const char *frmt, int *i, t_format *f);

// dispatch_bonus.c
int		dispatch_conversion(t_format *f, va_list args);

// numeric_bonus.c
char	*get_digits(unsigned long n, int base, int upper);
char	*pad_precision(char *digits, t_format *f);
char	*get_sign_prefix(t_format *f, int negative);
char	*get_hash_prefix(t_format *f, unsigned long value);

// output_bonus.c
int		output_padded(t_format *f, const char *prefix,
			const char *digits, int is_numeric);
int		output_char(t_format *f, char c);

// handlers_bonus.c
int		handle_int(t_format *f, va_list args);
int		handle_uint(t_format *f, va_list args, int base, int upper);
int		handle_str(t_format *f, va_list args);
int		handle_char(t_format *f, va_list args);
int		handle_ptr(t_format *f, va_list args);

#endif

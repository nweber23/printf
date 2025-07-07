/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:19:09 by nweber            #+#    #+#             */
/*   Updated: 2025/07/07 16:58:52 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putnbr(int n)
{
	int		ret;
	int		len;
	long	nb;

	nb = n;
	if (n < 0)
	{
		ret = write(1, '-', 1);
		if (ret == -1)
			return (-1);
		len += ret;
		nb -= nb;
	}
	if (nb >= 10)
	{
		ret = putnbr(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = write(1, (n % 10) + '0', 1);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

int	putnbr_unsigned(unsigned int n)
{
	int	ret;
	int	len;

	len = 0;
	if (n >= 10)
	{
		ret = putnbr_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = write(1, (n % 10) + '0', 1);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

int	convert_hex(unsigned int n, char *charset)
{
	int	ret;
	int	len;

	len = 0;
	if (n >= 16)
	{
		ret = convert_hex(n / 16, charset);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = write(1, &charset[n % 16], 1);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}

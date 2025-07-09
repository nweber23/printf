/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:34:52 by nweber            #+#    #+#             */
/*   Updated: 2025/07/09 15:45:41 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <limits.h>
// #include "includes/ft_printf.h"

// int	main(void)
// {
// 	int		ret1, ret2;
// 	char	*str = "Hello, 42!";
// 	char	*nullstr = NULL;
// 	int		n = -42;
// 	unsigned int u = 4294967295U;
// 	void	*ptr = str;
// 	void	*null_ptr = NULL;

// 	printf("==== ft_printf vs printf tester ====\n\n");

// 	// %d and %i
// 	ret1 = ft_printf("ft_printf: d: %d, i: %i\n", n, n);
// 	ret2 = printf("printf   : d: %d, i: %i\n", n, n);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %u
// 	ret1 = ft_printf("ft_printf: u: %u\n", u);
// 	ret2 = printf("printf   : u: %u\n", u);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %x and %X
// 	ret1 = ft_printf("ft_printf: x: %x, X: %X\n", u, u);
// 	ret2 = printf("printf   : x: %x, X: %X\n", u, u);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %s
// 	ret1 = ft_printf("ft_printf: s: %s\n", str);
// 	ret2 = printf("printf   : s: %s\n", str);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %s with NULL
// 	ret1 = ft_printf("ft_printf: null string: %s\n", nullstr);
// 	ret2 = printf("printf   : null string: %s\n", nullstr);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %c
// 	ret1 = ft_printf("ft_printf: c: %c\n", 'A');
// 	ret2 = printf("printf   : c: %c\n", 'A');
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %p
// 	ret1 = ft_printf("ft_printf: p: %p\n", ptr);
// 	ret2 = printf("printf   : p: %p\n", ptr);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %p with NULL
// 	ret1 = ft_printf("ft_printf: null pointer: %p\n", null_ptr);
// 	ret2 = printf("printf   : null pointer: %p\n", null_ptr);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// %%
// 	ret1 = ft_printf("ft_printf: percent: %%\n");
// 	ret2 = printf("printf   : percent: %%\n");
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	// Edge cases: INT_MIN, INT_MAX, 0
// 	ret1 = ft_printf("ft_printf: INT_MIN: %d, INT_MAX: %d,
// 		zero: %d\n", INT_MIN, INT_MAX, 0);
// 	ret2 = printf("printf   : INT_MIN: %d, INT_MAX: %d,
// 		zero: %d\n", INT_MIN, INT_MAX, 0);
// 	printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

// 	return (0);
// }

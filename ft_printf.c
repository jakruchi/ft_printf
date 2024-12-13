/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakruchi <jakruchi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:29:41 by jakruchi          #+#    #+#             */
/*   Updated: 2024/12/13 23:15:23 by jakruchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_format_specifier(const char *str, va_list arg)
{
	int	count;

	count = 0;
	if (*(str + 1) == 'c')
		count = put_char(va_arg(arg, int));
	else if (*(str + 1) == 's')
		count = put_str(va_arg(arg, char *));
	else if (*(str + 1) == 'p')
		count = put_pointer(va_arg(arg, void *));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		count = put_nbr(va_arg(arg, int));
	else if (*(str + 1) == 'u')
		count = put_nbr(va_arg(arg, unsigned int));
	else if (*(str + 1) == 'x')
		count = put_hex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*(str + 1) == 'X')
		count = put_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (*(str + 1) == '%')
		count = put_char('%');
	else
		count = write(1, str + 1, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;

	va_start(ptr, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1))
		{
			count += process_format_specifier(str, ptr);
			str++;
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ptr);
	return (count);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main(void)
// {
//     int count;
//     printf("\n------------test-1------------\n");
//     count = printf("hello\n");
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello\n");
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-2------------\n");
//     count = printf("hello %c enough %c\n", 'a', 'b');
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %c enough %c\n", 'a', 'b');
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-3------------\n");
//     count = printf("hello %s enough %s %c\n", "honza", "is enough", 'a');
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %s enough %s %c\n", "honza", "is enough", 'a');
//     printf("ft_printf printed: %d characters\n", count);

//     int a = 10;
//     void *ptr = &a;
//     printf("\n------------test-4------------\n");
//     count = printf("hello %p\n", ptr);
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %p\n", ptr);
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-5------------\n");
//     count = printf("hello %x HELLO %X\n", 0, -98743298);
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %x HELLO %X\n", 0, -98743298);
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-6------------\n");
//     count = printf("hello %x HELLO %X%%\n", 0, -98743298);
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %x HELLO %X%%\n", 0, -98743298);
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-7------------\n");
//     // count = printf("hello %3 HELLO\n");
//     // printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %3 HELLO\n");
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-8------------\n");
//     count = printf("hello %d HELLO %i\n", INT_MAX, INT_MIN);
//     printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %d HELLO %i\n", INT_MAX, INT_MIN);
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-9------------\n");
//     // count = printf("hello %\n");
//     // printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %\n");
//     printf("ft_printf printed: %d characters\n", count);

//     printf("\n------------test-10------------\n");
//     // count = printf("hello %");
//     // printf("printf printed: %d characters\n", count);
//     count = ft_printf("hello %");
//     printf("ft_printf printed: %d characters\n", count);

//     return (0);
// }

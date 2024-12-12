/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:09:52 by jankruchina       #+#    #+#             */
/*   Updated: 2024/12/13 00:31:10 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include <stdlib.h>
#include <stdio.h>

int    put_char(char c)
{
    return (write(1, &c, 1));
}

int put_str(char *str)
{
    int count;

    count = 0;
    if (str == NULL)
		return (write(1, "(null)", 6));
    while (*str != '\0')
    {
        count += write(1, str, 1);
        str++;
    }
    return (count);
}

int put_hex(unsigned long num, const char *hex_chars)
{
    int count = 0;

    if (num >= 16)
        count += put_hex(num / 16, hex_chars);
    count += put_char(hex_chars[num % 16]);
    return count;
}

int put_pointer(void *ptr)
{
    unsigned long addr = (unsigned long)ptr; 
    int count = 0;

    if (ptr == NULL)
		return (write(1, "(nil)", 5));
    count += write(1, "0x", 2);
    count += put_hex(addr, "0123456789abcdef");
    return count;
}

int	put_nbr(long nbr)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		put_char('-');
		return (put_nbr(-nbr) + 1);
	}
	else if (nbr < 10)
		return (put_char(nbr + '0'));
	else
	{
		count = put_nbr(nbr / 10);
		return (count + put_nbr(nbr % 10));
	}
}

int    process_format_specifier(const char *str, va_list arg)
{
    int count;

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

int ft_printf(const char *str, ...)
{
    int count;
    va_list ptr;
    va_start(ptr, str);
    count = 0;
    while (*str != '\0')
    {
        if (*str == '%')
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

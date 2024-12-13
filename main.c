/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:41:38 by jankruchina       #+#    #+#             */
/*   Updated: 2024/12/13 19:05:00 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int count;
    printf("\n------------test-1------------\n");
    count = printf("hello\n");
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello\n");
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-2------------\n");
    count = printf("hello %c enough %c\n", 'a', 'b');
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %c enough %c\n", 'a', 'b');
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-3------------\n");
    count = printf("hello %s enough %s %c\n", "honza", "is enough", 'a');
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %s enough %s %c\n", "honza", "is enough", 'a');
    printf("ft_printf printed: %d characters\n", count);

    int a = 10;
    void *ptr = &a;
    printf("\n------------test-4------------\n");
    count = printf("hello %p\n", ptr);
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %p\n", ptr);
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-5------------\n");
    count = printf("hello %x HELLO %X\n", 123, -98743298);
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %x HELLO %X\n", 123, -98743298);
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-6------------\n");
    count = printf("hello %x HELLO %X%%\n", 0, -98743298);
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %x HELLO %X%%\n", 0, -98743298);
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-7------------\n");
    // count = printf("hello %3 HELLO\n");
    // printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %3 HELLO\n");
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-8------------\n");
    count = printf("hello %d HELLO %i\n", INT_MAX, INT_MIN);
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %d HELLO %i\n", INT_MAX, INT_MIN);
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-9------------\n");
    // count = printf("hello %\n");
    // printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %\n");
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-10------------\n");
    // count = printf("hello %");
    // printf("printf printed: %d characters\n", count);
    count = ft_printf("hello %");
    printf("ft_printf printed: %d characters\n", count);
    // char    *idk = "ahojda";

    printf("\n------------test-11------------\n");
    count = printf("%p", NULL);
    printf("printf printed: %d characters\n", count);
    count = ft_printf("%p", NULL);
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-12------------\n");
    count = printf("%ca%cb%c%c", 0, 0, 0, 0);
    printf("\nprintf printed: %d characters\n", count);
    count = ft_printf("%ca%cb%c%c", 0, 0, 0, 0);
    printf("\nft_printf printed: %d characters\n", count);

    int temp = 12435;
    printf("\n------------test-13------------\n");
    count = printf("hex of %d is: %x and %X\n", temp, temp, temp);
    printf("printf printed: %d characters\n", count);
    count = ft_printf("hex of %d is: %x and %X\n", temp, temp, temp);
    printf("ft_printf printed: %d characters\n", count);

    printf("\n------------test-14------------\n");
    // count = printf(NULL);
    // printf("printf printed: %d characters\n", count);
    count = ft_printf(NULL);
    printf("ft_printf printed: %d characters\n", count);

    return (0);
}

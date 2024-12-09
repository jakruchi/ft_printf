/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:09:52 by jankruchina       #+#    #+#             */
/*   Updated: 2024/12/09 22:37:36 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int ft_print(const char *, ...)
// {
    
// }

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int ft_print(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0; // To track the number of characters printed

    while (*format) {
        if (*format == '%' && *(format + 1)) {
            format++; // Move past the '%'
            switch (*format) {
                case 'd': { // Handle integers
                    int i = va_arg(args, int);
                    count += printf("%d", i);
                    break;
                }
                case 'c': { // Handle characters
                    int c = va_arg(args, int); // char is promoted to int in va_arg
                    count += printf("%c", c);
                    break;
                }
                case 's': { // Handle strings
                    const char *s = va_arg(args, const char *);
                    count += printf("%s", s);
                    break;
                }
                default: // Handle unknown format specifiers
                    count += printf("%%");
                    count += printf("%c", *format);
            }
        } else {
            putchar(*format); // Print regular characters
            count++;
        }
        format++;
    }

    va_end(args);
    return count; // Return the total number of characters printed
}

int main() {
    int count = ft_print("Hello, %s! Your score is %d. Initial: %c\n", "Alice", 95, 'A');
    printf("Total characters printed: %d\n", count);
    return 0;
}

// int main(void)
// {
    
//     ft_printf("fuck");
//     printf("hello world");
//     return (0);
// }
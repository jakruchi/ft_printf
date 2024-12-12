/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:25:34 by jankruchina       #+#    #+#             */
/*   Updated: 2024/12/12 23:04:40 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
// # include <stdlib.h>
# include <stdarg.h>

int    put_char(char c);
int put_str(char *str);
int put_hex(unsigned long num, const char *hex_chars);
int put_pointer(void *ptr);
int    process_format_specifier(const char *str, va_list arg);
int ft_printf(const char *str, ...);
int	put_nbr(long nbr);

#endif
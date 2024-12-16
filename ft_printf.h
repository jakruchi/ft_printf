/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakruchi <jakruchi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:29:11 by jakruchi          #+#    #+#             */
/*   Updated: 2024/12/16 21:18:08 by jakruchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* ft_print.c */
int	process_format_specifier(const char *str, va_list arg);
int	ft_printf(const char *str, ...);

/* ft_print_utils.c */
int	put_char(char c);
int	put_str(char *str);
int	put_hex(unsigned long num, const char *hex_chars);
int	put_pointer(void *ptr);
int	put_nbr(long nbr);

#endif

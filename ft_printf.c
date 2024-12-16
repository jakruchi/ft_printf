/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakruchi <jakruchi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:29:41 by jakruchi          #+#    #+#             */
/*   Updated: 2024/12/16 22:10:12 by jakruchi         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakruchi <jakruchi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:29:27 by jakruchi          #+#    #+#             */
/*   Updated: 2024/12/13 23:00:41 by jakruchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char c)
{
	return (write(1, &c, 1));
}

int	put_str(char *str)
{
	int	count;

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

int	put_hex(unsigned long num, const char *hex_chars)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += put_hex(num / 16, hex_chars);
	count += put_char(hex_chars[num % 16]);
	return (count);
}

int	put_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += put_hex(addr, "0123456789abcdef");
	return (count);
}

int	put_nbr(long nbr)
{
	int	count;

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

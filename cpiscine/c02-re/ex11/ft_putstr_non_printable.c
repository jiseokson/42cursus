/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:18:20 by jison             #+#    #+#             */
/*   Updated: 2022/10/10 15:24:21 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_char_printable(unsigned char c)
{
	return (32 <= c && c <= 126);
}

void	put_non_printable_char(unsigned char c)
{
	char	*hex_digit;

	hex_digit = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, hex_digit + (c / 16), 1);
	write(1, hex_digit + (c % 16), 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (*ptr)
	{
		if (is_char_printable(*ptr))
			write(1, ptr, 1);
		else
			put_non_printable_char(*ptr);
		++ptr;
	}
}

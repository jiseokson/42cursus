/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:18:20 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 17:49:21 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_char_printable(char c)
{
	return (32 <= c && c <= 126);
}

void	put_non_printable_char(char c)
{
	char	*hex_digit;

	hex_digit = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, hex_digit + (c / 16), 1);
	write(1, hex_digit + (c % 16), 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_char_printable(*str))
			write(1, str, 1);
		else
			put_non_printable_char(*str);
		++str;
	}
}

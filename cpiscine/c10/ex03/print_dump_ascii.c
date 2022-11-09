/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dump_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:19:15 by jison             #+#    #+#             */
/*   Updated: 2022/10/19 19:40:04 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_dump.h"
#include "ft_print.h"

void	print_hex_num(long long n, int padding)
{
	char	*hex_digit;

	if (padding == 0)
		return ;
	hex_digit = "0123456789abcdef";
	print_hex_num(n / 16, padding - 1);
	ft_fprint_char(1, hex_digit[n % 16]);
}

void	print_offset(long long offset, int padding)
{
	print_hex_num(offset, padding);
	ft_fprint(1, "  ");
}

void	print_dump_by_hex(char *content, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)content;
	i = -1;
	while (++i < 16)
	{
		if (i < size)
			print_hex_num(ptr[i], 2);
		else
			ft_fprint(1, "  ");
		ft_fprint(1, " ");
		if (i == 7)
			ft_fprint(1, " ");
	}
	ft_fprint(1, " ");
}

void	print_dump_by_ascii(char *content, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)content;
	ft_fprint(1, "|");
	i = -1;
	while (++i < size)
	{
		if (32 <= content[i] && content[i] <= 126)
			ft_fprint_char(1, (char)content[i]);
		else
			ft_fprint_char(1, '.');
	}
	ft_fprint(1, "|\n");
}

void	print_dump_ascii(char *content, long long size)
{
	long long	block_index;
	long long	remain_bytes;

	block_index = 0;
	remain_bytes = size;
	while (block_index * 16 < size)
	{
		print_offset(block_index * 16, 8);
		print_dump_by_hex(content + block_index * 16,\
		(remain_bytes >= 16) * 16 + (remain_bytes < 16) * remain_bytes);
		print_dump_by_ascii(content + block_index * 16,\
		(remain_bytes >= 16) * 16 + (remain_bytes < 16) * remain_bytes);
		++block_index;
		remain_bytes -= 16;
	}
}

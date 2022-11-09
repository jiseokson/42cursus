/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dump_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:19:15 by jison             #+#    #+#             */
/*   Updated: 2022/10/19 22:45:14 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_dump.h"
#include "ft_string.h"
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
}

void	print_dump_by_hex(char *content, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)content;
	i = -1;
	ft_fprint(1, "  ");
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

void	print_line_ascii(char *content, long long block_index, long long remain_bytes)
{
	print_offset(block_index * 16, 8);
	print_dump_by_hex(
	content + block_index * 16,
		(remain_bytes >= 16) * 16 + (remain_bytes < 16) * remain_bytes
		);
	print_dump_by_ascii(
		content + block_index * 16,
		(remain_bytes >= 16) * 16 + (remain_bytes < 16) * remain_bytes
		);
}

void	print_dump_ascii(char *content, long long size)
{
	long long	block_index;
	long long	remain_bytes;

	print_line_ascii(content, 0, size);
	block_index = 1;
	remain_bytes = size - 16;
	while (block_index * 16 < size)
	{
		if (block_index * 16 < size
				&& !ft_strncmp(content + block_index * 16 - 16, content + block_index * 16, 16))
			ft_fprint(1, "*\n");
		while (block_index * 16 < size
				&& !ft_strncmp(content + block_index * 16 - 16, content + block_index * 16, 16))
		{
			++block_index;
			remain_bytes -= 16;
		}
		print_line_ascii(content, block_index, remain_bytes);
		++block_index;
		remain_bytes -= 16;
	}
	print_offset(block_index * 16, 8);
	ft_fprint(1, "\n");
}





void	hexdump(int ac, char **av)
{
	int	fd;
	long long	block_index;
	long long	remain_bytes;


	remain_bytes = 0;
	while (*(++av))
	{
		if (0 <= remain_bytes && remain_bytes < 16)
		{
			fd = open_file(*av);
			if (fd < 0)
			{
				// file error
				continue ;
			}
			buffer = read_content(fd); // read error..????
			dump = new_content(dump, buffer);
			remain_bytes += ft_strlen(buffer);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:30:48 by jison             #+#    #+#             */
/*   Updated: 2022/10/19 11:55:00 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(long long n, int padding)
{
	char	*hex_digit;

	if (padding == 0)
		return ;
	hex_digit = "0123456789abcdef";
	print_hex(n / 16, padding - 1);
	write(1, hex_digit + (n % 16), 1);
}

void	print_memory_addr(void *addr)
{
	print_hex((long long)addr, 16);
	write(1, ": ", 2);
}

void	print_content_by_hex(void *addr, int count)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = (unsigned char *)addr;
	while (i < count)
	{
		print_hex(*(ptr + i), 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		++i;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		++i;
	}
}

void	print_content_by_char(void *addr, int count)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = (unsigned char *)addr;
	while (i < count)
	{
		if (32 <= ptr[i] && ptr[i] <= 126)
			write(1, ptr + i, 1);
		else
			write(1, ".", 1);
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	block_index;
	unsigned int	remain_bytes;

	block_index = 0;
	remain_bytes = size;
	while (block_index * 16 < size)
	{
		print_memory_addr(addr + block_index * 16);
		if (remain_bytes >= 16)
		{
			print_content_by_hex(addr + block_index * 16, 16);
			print_content_by_char(addr + block_index * 16, 16);
		}
		else
		{
			print_content_by_hex(addr + block_index * 16, remain_bytes);
			print_content_by_char(addr + block_index * 16, remain_bytes);
		}
		write(1, "\n", 1);
		++block_index;
		remain_bytes -= 16;
	}
	return (addr);
}

int main(void)
{
	char str[100] = "sfsdgfsdfkjghsdfhugaruignioasdougbaerunhba";
	ft_print_memory((void *)str, sizeof(str));
	return 0;
}

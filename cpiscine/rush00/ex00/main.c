/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujlim <sujlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:59:52 by sujlim            #+#    #+#             */
/*   Updated: 2022/10/02 20:25:05 by sujlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	void	rush(int x, int y);

int	is_digit(const char c)
{
	return ('0' <= c && c <= '9');
}

int	is_numeric(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' && ! is_digit(str[1]))
		return (0);
	if (*str == '-')
		++str;
	while (*str)
	{
		if (! is_digit(*str))
			return (0);
		++str;
	}
	return (1);
}

int	to_int(const char *str)
{
	int	ret;
	int	i;

	if (*str == '-')
		return (-to_int(str + 1));
	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ret *= 10;
		ret += str[i] - '0';
		++i;
	}
	return (ret);
}

void	puts(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc == 1)
		puts("usage: rush <integer> <integer>\n");
	else if (argc != 3)
		puts("Error: Two integer values must be entered.\n");
	else if (! (is_numeric(argv[1]) && is_numeric(argv[2])))
		puts("Error: The input form must be in integer form.\n");
	else
	{
		x = to_int(argv[1]);
		y = to_int(argv[2]);
		if (! (x >= 1 && y >= 1))
		{
			puts("Error: The integer value must be greater than");
			puts(" or equal to 1.\n");
		}
		else
			rush(x, y);
	}
	return (0);
}

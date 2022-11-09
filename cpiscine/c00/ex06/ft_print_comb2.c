/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:04:23 by jison             #+#    #+#             */
/*   Updated: 2022/09/29 17:09:56 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit_2d(int n)
{
	char	buf;

	buf = (n / 10) + '0';
	write(1, &buf, 1);
	buf = (n % 10) + '0';
	write(1, &buf, 1);
}

void	print_pair(int *comb)
{
	char	white_space;

	white_space = ' ';
	print_digit_2d(comb[0]);
	write(1, &white_space, 1);
	print_digit_2d(comb[1]);
}

void	print_comb(int *comb, int i, int d)
{
	char	*del;

	del = ", ";
	if (i == 2)
	{
		print_pair(comb);
		if (comb[0] < 98)
			write(1, del, 2);
		return ;
	}
	if (d >= 100)
		return ;
	comb[i] = d;
	print_comb(comb, i + 1, d + 1);
	print_comb(comb, i, d + 1);
}

void	ft_print_comb2(void)
{
	int	comb[2];

	print_comb(comb, 0, 0);
}

int	main(int argc, char **argv)
{
	return (0);
}

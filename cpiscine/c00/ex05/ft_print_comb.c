/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:01:01 by jison             #+#    #+#             */
/*   Updated: 2022/09/29 17:01:30 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(char *comb, int i, char d)
{
	char	*del;

	del = ", ";
	if (i == 3)
	{
		write(1, comb, 3);
		if (comb[0] < '7')
			write(1, del, 2);
		return ;
	}
	if (d > '9')
		return ;
	comb[i] = d;
	print_comb(comb, i + 1, d + 1);
	print_comb(comb, i, d + 1);
}

void	ft_print_comb(void)
{
	char	comb[3];

	print_comb(comb, 0, '0');
}

int	main(int argc, char **argv)
{
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:07:35 by jison             #+#    #+#             */
/*   Updated: 2022/09/29 17:07:42 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pair(int *comb, int n)
{
	int		i;
	char	buf;

	i = 0;
	while (i < n)
	{
		buf = comb[i] + '0';
		write(1, &buf, 1);
		++i;
	}
}

void	print_comb(int *comb, int n, int i, int d)
{
	char	*del;

	del = ", ";
	if (i == n)
	{
		print_pair(comb, n);
		if (comb[0] < 10 - n)
			write(1, del, 2);
		return ;
	}
	if (d >= 10)
		return ;
	comb[i] = d;
	print_comb(comb, n, i + 1, d + 1);
	print_comb(comb, n, i, d + 1);
}

void	ft_print_combn(int n)
{
	int	comb[10];

	print_comb(comb, n, 0, 0);
}

int	main(int argc, char **agrv)
{
	return (0);
}

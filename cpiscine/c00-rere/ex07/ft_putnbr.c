/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:05:27 by jison             #+#    #+#             */
/*   Updated: 2022/10/01 22:49:12 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_uint(long long n)
{
	char	buf;

	if (n / 10 != 0)
		put_uint(n / 10);
	buf = (n % 10) + '0';
	write(1, &buf, 1);
}

void	ft_putnbr(int nb)
{
	long long	llnb;

	llnb = nb;
	if (llnb < 0)
	{
		llnb = -llnb;
		write(1, "-", 1);
	}
	put_uint(llnb);
}

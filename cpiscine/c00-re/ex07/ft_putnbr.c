/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:05:27 by jison             #+#    #+#             */
/*   Updated: 2022/10/01 16:49:43 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_uint(int n)
{
	char	buf;

	if (n / 10 != 0)
		put_uint(n / 10);
	buf = (n % 10) + '0';
	write(1, &buf, 1);
}

void	ft_putnbr(int nb)
{
	char	neg_sign;

	neg_sign = '-';
	if (nb < 0)
	{
		nb = -nb;
		write(1, &neg_sign, 1);
	}
	put_uint(nb);
}

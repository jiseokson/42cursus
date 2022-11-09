/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:24:27 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 19:36:50 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long long	llnb;
	char		*dec_digit;

	llnb = (long long)nb;
	dec_digit = "0123456789";
	if (llnb < 0)
	{
		llnb = -llnb;
		write(1, "-", 1);
	}
	if (llnb / 10 != 0)
		ft_putnbr((int)(llnb / 10));
	write(1, dec_digit + (llnb % 10), 1);
}

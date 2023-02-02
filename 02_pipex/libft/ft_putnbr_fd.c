/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:02:38 by jison             #+#    #+#             */
/*   Updated: 2022/11/11 12:41:59 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_putnbr_recur_fd(int n, int fd)
{
	if (n == 0)
		return ;
	ft_putnbr_recur_fd(n / 10, fd);
	ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_recur_fd(n, fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:50:00 by jison             #+#    #+#             */
/*   Updated: 2022/10/13 14:33:23 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	long long	len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

void	ft_putnum(int n)
{
	char	*dec_digit;

	dec_digit = "0123456789";
	if (n / 10 != 0)
		ft_putnum(n / 10);
	write(1, dec_digit + (n % 10), 1);
}

void	ft_show_tab(t_stock_str *par)
{
	long long	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnum(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		++i;
	}
}

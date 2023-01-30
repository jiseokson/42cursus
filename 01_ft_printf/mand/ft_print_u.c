/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:59:25 by jison             #+#    #+#             */
/*   Updated: 2022/11/24 14:03:41 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u_dec(unsigned int n, int precision, int width, t_spec *spec)
{
	int	printed;

	printed = 0;
	if (n / 10 != 0)
		printed += ft_print_u_dec(n / 10, precision - 1, width - 1, spec);
	else
		printed += ft_print_precision(precision - 1, width - 1, spec);
	printed += write(1, &DEC[ft_abs(n % 10)], 1);
	return (printed);
}

void	config_u_spec(t_spec *spec)
{
	if (spec->zero_pad && !spec->precision_flag)
	{
		spec->pad_chr = '0';
		if (spec->head)
			spec->precision = spec->width - 1;
	}
}

int	ft_print_u(unsigned int arg, t_spec *spec)
{
	int	printed;

	printed = 0;
	config_u_spec(spec);
	if (!spec->left_adjust)
	{
		if (spec->precision_flag && spec->precision == 0 && arg == 0)
			printed += ft_print_precision(spec->precision, spec->width, spec);
		else
			printed += ft_print_u_dec(arg, spec->precision, spec->width, spec);
	}
	else
	{
		if (spec->precision_flag && spec->precision == 0 && arg == 0)
			printed += ft_print_precision(spec->precision, 0, spec);
		else
			printed += ft_print_u_dec(arg, spec->precision, 0, spec);
		while (printed < spec->width)
			printed += write(1, " ", 1);
	}
	return (printed);
}

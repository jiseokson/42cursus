/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:58:16 by jison             #+#    #+#             */
/*   Updated: 2022/11/24 13:59:56 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_dec(int n, int precision, int width, t_spec *spec)
{
	int	printed;

	printed = 0;
	if (n / 10 != 0)
		printed += ft_print_d_dec(n / 10, precision - 1, width - 1, spec);
	else
		printed += ft_print_precision(precision - 1, width - 1, spec);
	printed += write(1, &DEC[ft_abs(n % 10)], 1);
	return (printed);
}

void	config_d_spec(int arg, t_spec *spec)
{
	if (arg < 0)
		spec->head = "-";
	if (spec->sign)
	{
		if (arg >= 0)
			spec->head = "+";
		else
			spec->head = "-";
	}
	else if (spec->blank_sign)
	{
		if (arg >= 0)
			spec->head = " ";
		else
			spec->head = "-";
	}
	if (spec->zero_pad && !spec->precision_flag)
	{
		spec->pad_chr = '0';
		if (spec->head)
			spec->precision = spec->width - 1;
	}
}

int	ft_print_d(int arg, t_spec *spec)
{
	int	printed;

	printed = 0;
	config_d_spec(arg, spec);
	if (!spec->left_adjust)
	{
		if (spec->precision_flag && spec->precision == 0 && arg == 0)
			printed += ft_print_precision(spec->precision, spec->width, spec);
		else
			printed += ft_print_d_dec(arg, spec->precision, spec->width, spec);
	}
	else
	{
		if (spec->precision_flag && spec->precision == 0 && arg == 0)
			printed += ft_print_precision(spec->precision, 0, spec);
		else
			printed += ft_print_d_dec(arg, spec->precision, 0, spec);
		while (printed < spec->width)
			printed += write(1, " ", 1);
	}
	return (printed);
}

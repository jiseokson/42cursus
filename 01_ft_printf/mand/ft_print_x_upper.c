/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:33:55 by jison             #+#    #+#             */
/*   Updated: 2022/11/24 14:12:12 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_up(unsigned int n, int precision, int width, t_spec *spec)
{
	int	printed;

	printed = 0;
	if (n / 16 != 0)
		printed += ft_print_x_up(n / 16, precision - 1, width - 1, spec);
	else
		printed += ft_print_precision(precision - 1, width - 1, spec);
	printed += write(1, &HEX_UPPER[ft_abs(n % 16)], 1);
	return (printed);
}

void	config_x_up_spec(unsigned int arg, t_spec *spec)
{
	if (spec->alter_form && arg != 0)
		spec->head = "0X";
	if (spec->zero_pad && !spec->precision_flag)
	{
		spec->pad_chr = '0';
		if (spec->head)
			spec->precision = spec->width - 2;
	}
}

int	ft_print_x_upper(unsigned int arg, t_spec *spec)
{
	int	printed;

	printed = 0;
	config_x_up_spec(arg, spec);
	if (!spec->left_adjust)
	{
		if (spec->precision_flag && spec->precision == 0 && arg == 0)
			printed += ft_print_precision(spec->precision, spec->width, spec);
		else
			printed += ft_print_x_up(arg, spec->precision, spec->width, spec);
	}
	else
	{
		if (spec->precision_flag && spec->precision == 0 && arg == 0)
			printed += ft_print_precision(spec->precision, 0, spec);
		else
			printed += ft_print_x_up(arg, spec->precision, 0, spec);
		while (printed < spec->width)
			printed += write(1, " ", 1);
	}
	return (printed);
}

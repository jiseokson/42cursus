/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:07:48 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 14:29:49 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p_hex(unsigned long n, int precision, int width, t_spec *spec)
{
	int	printed;

	printed = 0;
	if (n / 16 != 0)
		printed += ft_print_p_hex(n / 16, precision - 1, width - 1, spec);
	else
		printed += ft_print_precision(precision - 1, width - 1, spec);
	printed += write(1, &HEX_LOWER[ft_abs(n % 16)], 1);
	return (printed);
}

int	ft_print_p(void *arg, t_spec *spec)
{
	int				printed;
	unsigned long	n;

	printed = 0;
	n = (unsigned long)arg;
	spec->head = "0x";
	spec->pad_chr = ' ';
	if (!spec->left_adjust)
		printed += ft_print_p_hex(n, spec->precision, spec->width, spec);
	else
	{
		printed += ft_print_p_hex((long long)arg, spec->precision, 0, spec);
		while (printed < spec->width)
			printed += write(1, " ", 1);
	}
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:32:56 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 14:27:23 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char arg, t_spec *spec)
{
	int		printed;

	printed = 0;
	spec->pad_chr = ' ';
	if (!spec->left_adjust)
	{
		printed += ft_print_width(spec->width - 1, spec);
		printed += write(1, &arg, 1);
	}
	else
	{
		printed += write(1, &arg, 1);
		while (printed < spec->width)
			printed += write(1, " ", 1);
	}
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:35:19 by jison             #+#    #+#             */
/*   Updated: 2022/11/24 14:44:05 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(const char **format, va_list args)
{
	int		printed;
	t_spec	spec;

	printed = 0;
	parse_conversion(format, &spec);
	if (spec.conversion == 'c')
		printed = ft_print_c(va_arg(args, int), &spec);
	else if (spec.conversion == 's')
		printed = ft_print_s(va_arg(args, char *), &spec);
	else if (spec.conversion == 'p')
		printed = ft_print_p(va_arg(args, void *), &spec);
	else if (spec.conversion == 'd')
		printed = ft_print_d(va_arg(args, int), &spec);
	else if (spec.conversion == 'i')
		printed = ft_print_i(va_arg(args, int), &spec);
	else if (spec.conversion == 'u')
		printed = ft_print_u(va_arg(args, unsigned int), &spec);
	else if (spec.conversion == 'x')
		printed = ft_print_x(va_arg(args, unsigned int), &spec);
	else if (spec.conversion == 'X')
		printed = ft_print_x_upper(va_arg(args, unsigned int), &spec);
	else if (spec.conversion == '%')
		printed = ft_print_percentage(&spec);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	args;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (match_conversion(format))
			printed += ft_print_arg(&format, args);
		else
			printed += write(1, format++, 1);
	}
	va_end(args);
	return (printed);
}

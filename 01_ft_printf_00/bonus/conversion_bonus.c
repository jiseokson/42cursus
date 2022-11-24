/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:23:10 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 14:52:14 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	match_conversion(const char *format)
{
	if (*format && *format == '%')
		++format;
	else
		return (0);
	while (*format && is_chrset(*format, FLAG))
		++format;
	while (*format && is_digit(*format))
		++format;
	if (*format && *format == '.')
	{
		++format;
		while (*format && is_digit(*format))
			++format;
	}
	if (*format && is_chrset(*format, CONVERSION))
		return (1);
	else
		return (0);
}

void	parse_flag(const char **format, t_spec *spec)
{
	while (**format && is_chrset(**format, FLAG))
	{
		if (**format == '#')
			spec->alter_form = 1;
		else if (**format == '0')
			spec->zero_pad = 1;
		else if (**format == '-')
			spec->left_adjust = 1;
		else if (**format == ' ')
			spec->blank_sign = 1;
		else if (**format == '+')
			spec->sign = 1;
		++(*format);
	}
}

void	parse_width(const char **format, t_spec *spec)
{
	if (**format && is_digit(**format))
		spec->width = (int)ft_strtol(*format, format);
}

void	parse_precision(const char **format, t_spec *spec)
{
	if (**format && **format == '.')
	{
		spec->precision_flag = 1;
		++(*format);
		spec->precision = (int)ft_strtol(*format, format);
	}
}

void	parse_conversion(const char **format, t_spec *spec)
{
	ft_memset(spec, 0, sizeof(*spec));
	spec->pad_chr = ' ';
	++(*format);
	parse_flag(format, spec);
	parse_width(format, spec);
	parse_precision(format, spec);
	spec->conversion = **format;
	++(*format);
}

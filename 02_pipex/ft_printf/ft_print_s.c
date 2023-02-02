/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:43 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 12:31:02 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_print_s_str(char *str)
{
	int		printed;
	char	*ptr;

	printed = 0;
	ptr = str;
	while (*ptr)
		printed += write(1, ptr++, 1);
	return (printed);
}

void	config_s_spec(char *arg, t_spec *spec)
{
	spec->pad_chr = ' ';
	if (spec->precision_flag && spec->precision < ft_p_strlen(arg))
		arg[spec->precision] = '\0';
}

int	ft_print_s(char *arg, t_spec *spec)
{
	int		printed;

	if (!arg)
		arg = "(null)";
	arg = ft_strdup(arg);
	if (!arg)
		return (0);
	printed = 0;
	config_s_spec(arg, spec);
	if (!spec->left_adjust)
	{
		printed += ft_print_width(spec->width - ft_p_strlen(arg), spec);
		printed += ft_print_s_str(arg);
	}
	else
	{
		printed += ft_print_s_str(arg);
		while (printed < spec->width)
			printed += write(1, " ", 1);
	}
	free(arg);
	return (printed);
}

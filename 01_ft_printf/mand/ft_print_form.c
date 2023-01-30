/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:28:37 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 14:27:33 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(int width, t_spec *spec)
{
	int	printed;

	printed = 0;
	while (width > 0)
	{
		printed += write(1, &spec->pad_chr, 1);
		--width;
	}
	return (printed);
}

int	ft_print_head(int width, t_spec *spec)
{
	int		printed;
	char	*head;

	printed = 0;
	head = spec->head;
	printed += ft_print_width(width - ft_strlen(head), spec);
	while (head && *head)
	{
		printed += write(1, head, 1);
		++head;
		--width;
	}
	return (printed);
}

int	ft_print_precision(int precision, int width, t_spec *spec)
{
	int	printed;

	printed = 0;
	if (precision > 0)
	{
		printed += ft_print_precision(precision - 1, width - 1, spec);
		printed += write(1, "0", 1);
	}
	else
		printed += ft_print_head(width, spec);
	return (printed);
}

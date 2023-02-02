/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:40:57 by jison             #+#    #+#             */
/*   Updated: 2023/02/02 17:43:45 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *format, ...)
{
	int		printed;
	int		temp_fd;
	va_list	args;

	printed = 0;
	temp_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	va_start(args, format);
	while (*format)
	{
		if (match_conversion(format))
			printed += ft_print_arg(&format, args);
		else
			printed += write(1, format++, 1);
	}
	va_end(args);
	dup2(temp_fd, STDOUT_FILENO);
	return (printed);
}

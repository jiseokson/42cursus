/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:23:39 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 12:32:15 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_chrset(const char c, const char *set)
{
	while (*set && *set != c)
		++set;
	return (*set == c);
}

int	is_digit(const char c)
{
	return (is_chrset(c, DEC));
}

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int	ft_p_strlen(const char *str)
{
	const char	*ptr;

	if (!str)
		return (0);
	ptr = str;
	while (*ptr)
		++ptr;
	return (ptr - str);
}

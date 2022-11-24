/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:23:39 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 14:28:09 by jison            ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;

	pb = (unsigned char *)b;
	while (len-- > 0)
		*pb++ = (unsigned char)c;
	return (b);
}

int	ft_strlen(const char *str)
{
	const char	*ptr;

	if (!str)
		return (0);
	ptr = str;
	while (*ptr)
		++ptr;
	return (ptr - str);
}

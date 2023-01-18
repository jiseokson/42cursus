/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:40:37 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 13:40:44 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memchr(const void *s, int c, ssize_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n > 0 && *ptr != (unsigned char)c)
	{
		++ptr;
		--n;
	}
	if (n > 0 && *ptr == (unsigned char)c)
		return ((void *)ptr);
	return (0);
}

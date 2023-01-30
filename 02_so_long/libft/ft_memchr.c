/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:13:08 by jison             #+#    #+#             */
/*   Updated: 2022/11/10 17:14:13 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:55:36 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 15:56:11 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (dst == 0 && src == 0)
		return (0);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	while (n-- > 0)
		*pdst++ = *psrc++;
	return (dst);
}

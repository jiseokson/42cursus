/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:50:19 by jison             #+#    #+#             */
/*   Updated: 2022/12/07 13:50:26 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

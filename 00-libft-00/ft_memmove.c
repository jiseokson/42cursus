/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:19:45 by jison             #+#    #+#             */
/*   Updated: 2022/11/10 17:48:43 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (dst == 0 && src == 0)
		return (0);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (pdst - psrc < 0 || (size_t)(pdst - psrc) >= len)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		pdst += len - 1;
		psrc += len - 1;
		while (len-- > 0)
			*pdst-- = *psrc--;
	}
	return (dst);
}

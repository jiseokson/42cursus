/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:19:45 by jison             #+#    #+#             */
/*   Updated: 2022/11/09 14:47:49 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (pdst - psrc >= len)
	{
		// pdst-psrc >= 0: ok, pdst-psrc < 0: 조건은 참이 되지만,,, 어차피 정방향복사 해야 하는 케이스이므로 괜춘
		ft_memcpy(dst, src, len);
	}
	else
	{
		// dst < src + len 이면 (문제가 되는 중복 상황) src의 내용이 덮어써져 의도하지 않은 동작
		pdst += len - 1;
		psrc += len - 1;
		while (len-- > 0)
			*pdst-- = *psrc--;
	}
	return (dst);
}

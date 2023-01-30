/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:16:01 by jison             #+#    #+#             */
/*   Updated: 2022/11/18 15:08:44 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, ssize_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (n == 0)
		return (dst);
	if (dst == 0 || src == 0)
		return (0);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	while (n-- > 0)
		*pdst++ = *psrc++;
	return (dst);
}

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

char	*ft_substr(const char *s, unsigned int start, ssize_t len)
{
	char	*ret;

	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, s + start, len);
	ret[len] = '\0';
	return (ret);
}

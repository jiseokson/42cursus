/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:43:55 by jison             #+#    #+#             */
/*   Updated: 2022/11/10 15:46:13 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*ptr;

	if (dstsize == 0)
		return (ft_strlen(src));
	ptr = src;
	while (--dstsize > 0 && *ptr)
		*dst++ = *ptr++;
	*dst = '\0';
	while (*ptr)
		++ptr;
	return (ptr - src);
}

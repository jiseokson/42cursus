/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:49:37 by jison             #+#    #+#             */
/*   Updated: 2022/12/07 13:52:35 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	substr_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr_len = 0;
		start = s_len;
	}
	else
		substr_len = ft_min(ft_strlen(s + start), len);
	ret = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, s + start, substr_len + 1);
	ret[substr_len] = '\0';
	return (ret);
}

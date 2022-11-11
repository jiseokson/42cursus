/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:08:57 by jison             #+#    #+#             */
/*   Updated: 2022/11/11 12:52:07 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char *set)
{
	while (*set && *set != c)
		++set;
	return (*set == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*lo;
	char	*hi;

	lo = (char *)s1;
	while (*lo && ft_isset(*lo, (char *)set))
		++lo;
	if (*lo == '\0')
		return (ft_substr(lo, 0, 0));
	hi = lo;
	while (*hi)
		++hi;
	--hi;
	while (ft_isset(*hi, (char *)set))
		--hi;
	++hi;
	return (ft_substr(lo, 0, hi - lo));
}

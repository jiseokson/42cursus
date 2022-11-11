/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:39:54 by jison             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:06 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	if ((char)c == '\0')
		return (ft_strchr(s, '\0'));
	ret = 0;
	while (*s)
	{
		s = ft_strchr(s, c);
		if (s == 0)
			break ;
		ret = (char *)s;
		++s;
	}
	return (ret);
}

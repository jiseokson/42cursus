/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:38:05 by jison             #+#    #+#             */
/*   Updated: 2022/11/11 12:51:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(s1) + 1;
	ret = (char *)malloc(size);
	if (ret == 0)
		return (0);
	ft_memcpy(ret, s1, size);
	return ((char *)ret);
}

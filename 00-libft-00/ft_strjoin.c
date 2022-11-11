/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:39:54 by jison             #+#    #+#             */
/*   Updated: 2022/11/10 20:45:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	ret_size;

	ret_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(ret_size * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, ret_size);
	ft_strlcat(ret, s2, ret_size);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:38:06 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 15:01:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

char	*ft_gnl_substr(const char *s, unsigned int start, ssize_t len)
{
	char	*ret;

	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, s + start, len);
	ret[len] = '\0';
	return (ret);
}

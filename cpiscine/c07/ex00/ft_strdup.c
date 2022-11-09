/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:51:31 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 12:42:34 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

char	*my_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (my_strlen(src) + 1));
	if (! ret)
		return (0);
	my_strcpy(ret, src);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:49:13 by jison             #+#    #+#             */
/*   Updated: 2022/10/19 21:58:56 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (*s1 && *s1 == *s2 && ++i < n)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*dest)
		++dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*dest)
		++dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

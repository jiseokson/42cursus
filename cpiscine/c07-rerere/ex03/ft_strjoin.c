/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:45:22 by jison             #+#    #+#             */
/*   Updated: 2022/10/12 15:27:40 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_strlen(char *str)
{
	long long	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

long long	get_ret_len(int size, char **strs, char *sep)
{
	int			i;
	long long	ret;

	i = -1;
	ret = 0;
	while (++i < size)
		ret += ft_strlen(strs[i]);
	ret += ((long long)(size - 1)) * ft_strlen(sep);
	return (ret);
}

void	ft_strcpy(char **dest, char *src)
{
	while (*src)
		*(*dest)++ = *src++;
}

void	join(char *ret, int size, char **strs, char *sep)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ft_strcpy(&ret, strs[i]);
		if (i < size - 1)
			ft_strcpy(&ret, sep);
	}
	*ret = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;

	if (size == 0)
	{
		ret = (char *)malloc(sizeof(char));
		if (! ret)
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (get_ret_len(size, strs, sep) + 1));
	if (! ret)
		return (0);
	join(ret, size, strs, sep);
	return (ret);
}

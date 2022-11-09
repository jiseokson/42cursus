/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:42:21 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 12:47:28 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		++sep;
	}
	return (0);
}

long long	get_ret_len(int size, char **strs, char *sep)
{
	int			i;
	long long	j;
	long long	ret;

	i = -1;
	ret = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			if (! is_sep(strs[i][j], sep))
				++ret;
			++j;
		}
	}
	return (ret);
}

void	join(char *ret, int size, char **strs, char *sep)
{
	int			i;
	long long	j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			if (! is_sep(strs[i][j], sep))
				*ret++ = strs[i][j];
			++j;
		}
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

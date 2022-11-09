/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:42:21 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 19:44:16 by jison            ###   ########.fr       */
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

int	is_match(char *str, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (! (str[i] && str[i] == sep[i]))
			return (0);
		++i;
	}
	return (1);
}

long long	get_ret_len(int size, char **strs, char *sep)
{
	int			i;
	long long	j;
	long long	sep_len;
	long long	ret;

	i = -1;
	sep_len = ft_strlen(sep);
	ret = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			if (is_match(strs[i] + j, sep))
				j += sep_len;
			else
			{
				++ret;
				++j;
			}
		}
	}
	return (ret);
}

void	join(char *ret, int size, char **strs, char *sep)
{
	int			i;
	long long	j;
	long long	sep_len;

	i = -1;
	sep_len = ft_strlen(sep);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			if (is_match(strs[i] + j, sep))
				j += sep_len;
			else
				*ret++ = strs[i][j++];
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

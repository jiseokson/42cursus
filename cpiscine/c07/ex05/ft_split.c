/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:35:03 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 12:52:02 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

long long	count_word(char *str, char *charset)
{
	long long	i;
	long long	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			++i;
		if (str[i])
			++ret;
		while (str[i] && ! is_sep(str[i], charset))
			++i;
	}
	return (ret);
}

char	*new_word(char *str, long long lo, long long hi)
{
	long long	i;
	char		*ret;

	ret = (char *)malloc(sizeof(char) * (hi - lo + 1));
	if (! ret)
		return (0);
	i = 0;
	while (lo + i <= hi)
	{
		ret[i] = str[lo + i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	long long	i;
	long long	lo;
	long long	j;
	char		**ret;

	ret = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (! ret)
		return (0);
	i = 0;
	lo = -1;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			++i;
		if (str[i])
			lo = i;
		while (str[i] && ! is_sep(str[i], charset))
			++i;
		if (lo != -1)
			ret[j++] = new_word(str, lo, i - 1);
		lo = -1;
	}
	ret[j] = 0;
	return (ret);
}

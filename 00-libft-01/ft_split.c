/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:50:03 by jison             #+#    #+#             */
/*   Updated: 2022/11/11 12:08:47 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, int c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
			++ret;
		while (*s && *s != c)
			++s;
	}
	return (ret);
}

static char	**ft_clear_split(char **s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		++i;
	}
	free(s);
	return (0);
}

static char	*get_next(char **s, char c)
{
	char	*start;

	start = 0;
	while (**s && **s == c)
		++(*s);
	if (**s)
		start = *s;
	while (**s && **s != c)
		++(*s);
	return (start);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	*start;
	char	**ret;

	i = 0;
	str = (char *)s;
	ret = (char **)ft_calloc(count_word((char *)s, c) + 1, sizeof(char *));
	if (!ret)
		return (0);
	while (*str)
	{
		start = get_next(&str, c);
		if (start)
		{
			ret[i] = ft_substr(start, 0, str - start);
			if (!ret[i])
				return (ft_clear_split(ret, i));
			++i;
		}
	}
	return (ret);
}

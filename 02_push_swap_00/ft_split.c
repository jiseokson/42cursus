/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:40:31 by jison             #+#    #+#             */
/*   Updated: 2023/01/16 13:42:31 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word(const char *s)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		while (*s && is_space(*s))
			++s;
		if (*s)
			++ret;
		while (*s && !is_space(*s))
			++s;
	}
	return (ret);
}

char	**free_split(char **s, size_t size)
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

const char	*get_next_word(const char **s)
{
	const char	*start;

	start = NULL;
	while (**s && is_space(**s))
		++(*s);
	if (**s)
		start = *s;
	while (**s && !is_space(**s))
		++(*s);
	return (start);
}

char	**ft_split(const char *str)
{
	int			i;
	const char	*start;
	char		**ret;

	i = 0;
	ret = (char **)malloc((count_word(str) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (*str)
	{
		start = get_next_word(&str);
		if (start)
		{
			ret[i] = ft_substr(start, 0, str - start);
			if (!ret[i])
				return (free_split(ret, i));
			++i;
		}
	}
	ret[i] = NULL;
	return (ret);
}

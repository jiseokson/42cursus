/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:24:03 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 20:40:05 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_dict.h"

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (! is_empty(*line))
			return (0);
		++line;
	}
	return (1);
}

int	is_empty(char c)
{
	char	*spaces;

	spaces = "\t\n\v\f\r ";
	while (*spaces)
	{
		if (c == *spaces)
			return (1);
		++spaces;
	}
	return (0);
}

int	count_colon(char *line)
{
	int	ret;

	ret = 0;
	while (*line)
	{
		if (*line == ':')
			++ret;
		++line;
	}
	return (ret);
}

void	increaser(int *a, int *b)
{
	++(*a);
	++(*b);
}

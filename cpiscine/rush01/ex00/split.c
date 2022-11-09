/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:06:50 by jison             #+#    #+#             */
/*   Updated: 2022/10/09 22:49:11 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	print_error(char *str, int exit_code);
int	parse_int(char *str, int lo, int hi);

void	find_word_range(char *str, int *lo, int *hi)
{
	while (str[*hi] && str[*hi] == ' ')
		++(*hi);
	if (str[*hi])
		*lo = *hi;
	while (str[*hi] && str[*hi] != ' ')
		++(*hi);
}

int	count_word(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			++i;
		if (str[i])
			++ret;
		while (str[i] && str[i] != ' ')
			++i;
	}
	return (ret);
}

int	split(char *str, int puzzle[])
{
	int	i;
	int	j;
	int	lo;
	int	temp;

	i = 0;
	j = 0;
	lo = -1;
	if (count_word(str) != 16)
		return (print_error("Error: number of factors must be 16\n", 0));
	while (str[i])
	{
		find_word_range(str, &lo, &i);
		if (lo != -1)
		{
			temp = parse_int(str, lo, i - 1);
			if (temp == -1)
				return (print_error("Error: factor must be positive int\n", 0));
			if (! (1 <= temp && temp <= 4))
				return (print_error("Error: factor must between 1 and 4\n", 0));
			puzzle[j++] = temp;
		}
		lo = -1;
	}
	return (1);
}

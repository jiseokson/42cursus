/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:22:47 by jison             #+#    #+#             */
/*   Updated: 2022/10/15 16:32:16 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_space(char c)
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

int	ft_atoi(char *str)
{
	int	sign;
	int	ret;

	sign = 1;
	ret = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		++str;
	}
	return (sign * ret);
}

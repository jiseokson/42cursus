/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:55:02 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/19 14:06:06 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_printable(char c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *buffer, int len)
{
	int	ans;
	int	idx;

	ans = 0;
	idx = 0;
	while (idx < len - 3)
	{
		if (!is_num(buffer[idx]))
			return (0);
		ans = ans * 10 + buffer[idx] - '0';
		++idx;
	}
	return (ans);
}

void	make_info(char *buffer, char *info)
{
	info[0] = *buffer++;
	info[1] = *buffer++;
	info[2] = *buffer++;
	info[3] = '\0';
}

int	is_info(char now, char *info)
{
	return (now == info[0] || now == info[1]);
}

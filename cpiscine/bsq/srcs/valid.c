/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:29:09 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 12:16:55 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_valid_info(char *buffer)
{
	int	len;
	int	i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		++len;
	if (len < 4)
		return (0);
	i = -1;
	while (++i < len - 3)
		if (!is_num(buffer[i]))
			return (0);
	if (buffer[i] != buffer[i + 1]
		&& buffer[i + 1] != buffer[i + 2]
		&& buffer[i + 2] != buffer[i]
		&& is_printable(buffer[i])
		&& is_printable(buffer[i + 1])
		&& is_printable(buffer[i + 2]))
		return (len);
	return (0);
}

int	is_valid_height(char *buffer, int height)
{
	int	line;

	line = 0;
	while (*buffer)
	{
		if (*buffer == '\n')
			++line;
		++buffer;
	}
	return (line == height + 1);
}

int	is_valid_width(char *buffer)
{
	int	width;
	int	temp;

	width = 0;
	while (*buffer != '\n')
	{
		++width;
		++buffer;
	}
	++buffer;
	while (*buffer)
	{
		temp = 0;
		while (*buffer)
		{
			if (*buffer == '\n')
				break ;
			++temp;
			++buffer;
		}
		if (temp != width)
			return (0);
		++buffer;
	}
	return (width > 0);
}

int	is_valid_map(char *buffer, char *info)
{
	while (*buffer)
	{
		if (*buffer != '\n' && !is_info(*buffer, info))
			return (0);
		++buffer;
	}
	return (1);
}

int	is_valid(char *buffer)
{
	int		len;
	int		height;
	char	info[4];

	len = is_valid_info(buffer);
	if (!len)
		return (0);
	height = ft_atoi(buffer, len);
	if (height == 0)
		return (0);
	make_info(buffer + len - 3, info);
	if (!is_valid_height(buffer, height))
		return (0);
	if (!is_valid_width(buffer + len + 1))
		return (0);
	if (!is_valid_map(buffer + len + 1, info))
		return (0);
	return (1);
}

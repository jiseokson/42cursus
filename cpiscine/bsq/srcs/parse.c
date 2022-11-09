/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:55:15 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 17:25:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "map.h"
#include "util.h"

void	parse_info(char *buffer, int *height, int *width, char *info)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	make_info(buffer + i - 3, info);
	*height = ft_atoi(buffer, i);
	++i;
	*width = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		++i;
		++(*width);
	}
}

void	fill_map(t_map *map, char *buffer)
{
	int	i;

	while (*buffer && *buffer != '\n')
		++buffer;
	++buffer;
	i = 0;
	while (*buffer)
	{
		if (*buffer != '\n')
		{
			set(map, i / map->width, i % map->width, *buffer);
			++i;
		}
		++buffer;
	}
}

t_map	*parse_map(char *buffer)
{
	int		height;
	int		width;
	t_map	*map;
	char	info[4];

	parse_info(buffer, &height, &width, info);
	map = new_map(height, width);
	map->empty = info[0];
	map->obstacle = info[1];
	map->full = info[2];
	fill_map(map, buffer);
	return (map);
}

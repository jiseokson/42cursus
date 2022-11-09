/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:54:13 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 17:29:08 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

t_map	*new_map(int height, int width)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->chs = (int *)malloc(sizeof(int) * height * width);
	if (!map->chs)
	{
		free(map);
		return (0);
	}
	map->height = height;
	map->width = width;
	return (map);
}

void	free_map(t_map *map)
{
	free(map->chs);
	free(map);
}

int	in_range(t_map *map, int y, int x)
{
	return (0 <= y && y < map->height && 0 <= x && x <= map->width);
}

int	set(t_map *map, int y, int x, int ch)
{
	if (!in_range(map, y, x))
		return (-1);
	map->chs[y * map->width + x] = ch;
	return (ch);
}

int	at(t_map *map, int y, int x)
{
	if (!in_range(map, y, x))
		return (-1);
	return (map->chs[y * map->width + x]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:26:18 by jison             #+#    #+#             */
/*   Updated: 2022/10/20 11:44:22 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"
#include "map.h"
#include "parse.h"
#include "ft_print.h"
#include "solve.h"

int	find_max(t_map *cache)
{
	int	i;
	int	j;
	int	max;

	max = -1;
	i = -1;
	while (++i < cache->height)
	{
		j = -1;
		while (++j < cache->width)
		{
			if (max < at(cache, i, j))
				max = at(cache, i, j);
		}
	}
	return (max);
}

void	find_full(t_map *cache, int *full_y, int *full_x)
{
	int	i;
	int	y;
	int	x;
	int	max;

	max = find_max(cache);
	i = -1;
	while (++i < cache->height * cache->width)
	{
		y = i / cache->width;
		x = i % cache->width;
		if (at(cache, y, x) == max)
		{
			*full_y = y;
			*full_x = x;
			return ;
		}
	}
}

void	print_answer(t_map *map, t_map *cache)
{
	int	i;
	int	j;
	int	full_x;
	int	full_y;
	int	max;

	find_full(cache, &full_y, &full_x);
	max = at(cache, full_y, full_x);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (full_y - max < i && i <= full_y
				&& full_x - max < j && j <= full_x)
				ft_fprint_char(1, map->full);
			else
				ft_fprint_char(1, (char)at(map, i, j));
		}
		ft_fprint_char(1, '\n');
	}
}

void	refresh(t_map *cache)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cache->height)
	{
		j = -1;
		while (++j < cache->width)
			set(cache, i, j, -1);
	}
}

void	bsq(char *buffer)
{
	t_map	*map;
	t_map	*cache;
	int		i;
	int		j;

	map = parse_map(buffer);
	cache = new_map(map->height, map->width);
	refresh(cache);
	i = map->height;
	while (0 <= --i)
	{
		j = map->width;
		while (0 <= --j)
			if (at(cache, i, j) == -1)
				solve(map, cache, i, j);
	}
	print_answer(map, cache);
	free_map(map);
	free(cache);
}

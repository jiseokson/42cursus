/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:56:23 by jison             #+#    #+#             */
/*   Updated: 2022/10/20 11:49:04 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "map.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	solve(t_map *map, t_map *cache, int y, int x)
{
	int	min;

	if (!in_range(map, y, x) || (char)at(map, y, x) == map->obstacle)
		return (0);
	if (at(cache, y, x) != -1)
		return (at(cache, y, x));
	min = ft_min(solve(map, cache, y - 1, x), solve(map, cache, y, x - 1));
	min = ft_min(min, solve(map, cache, y - 1, x - 1));
	set(cache, y, x, min + 1);
	return (min + 1);
}

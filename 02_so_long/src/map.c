/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:50:59 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 20:32:36 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	new_map(int width, int height)
{
	t_map	map;

	map.width = width;
	map.height = height;
	map.map = (char *)malloc(sizeof(char) * width * height);
	if (map.map)
		ft_memset(map.map, MAP_COMP_NULL, width * height * sizeof(char));
	return (map);
}

t_map_comp	set(t_map map, int x, int y, t_map_comp comp)
{
	if (!in_range(map.width, map.height, x, y))
		return (-1);
	return (map.map[y * map.width + x] = comp);
}

t_map_comp	at(t_map map, int x, int y)
{
	if (!in_range(map.width, map.height, x, y))
		return (-1);
	return (map.map[y * map.width + x]);
}

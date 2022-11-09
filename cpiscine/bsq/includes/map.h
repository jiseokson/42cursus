/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:46:42 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 17:29:31 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		*chs;
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
}			t_map;

t_map	*new_map(int height, int width);
void	free_map(t_map *map);
int		in_range(t_map *map, int y, int x);
int		set(t_map *map, int y, int x, int ch);
int		at(t_map *map, int y, int x);

#endif

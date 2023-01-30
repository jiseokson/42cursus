/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:44:58 by jison             #+#    #+#             */
/*   Updated: 2023/01/30 13:28:17 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_file_chr(char *line, int *e_cnt, int *c_cnt, int *p_cnt)
{
	char	chr;

	while (*line)
	{
		chr = *line++;
		if (chr == MAP_COMP_EXIT_CHR)
			++(*e_cnt);
		else if (chr == MAP_COMP_COLLECTIBLE_CHR)
			++(*c_cnt);
		else if (chr == MAP_COMP_PLAYER_CHR)
			++(*p_cnt);
		else if (!(chr == MAP_COMP_BACK_CHR || chr == MAP_COMP_WALL_CHR))
			return (0);
	}
	return (1);
}

void	check_map_file_validity(char **lines)
{
	int	i;
	int	exit_cnt;
	int	collect_cnt;
	int	spawn_cnt;

	if (!lines[0])
		log_map_file_validity(lines, "There is no valid content in the file");
	i = -1;
	exit_cnt = 0;
	collect_cnt = 0;
	spawn_cnt = 0;
	while (lines[++i])
	{
		if (ft_strlen(lines[i]) > 0 \
			&& i > 0 && ft_strlen(lines[i - 1]) != ft_strlen(lines[i]))
			log_map_file_validity(lines, "The map is not a rectangle");
		if (!check_map_file_chr(lines[i], &exit_cnt, &collect_cnt, &spawn_cnt))
			log_map_file_validity(lines, "Use undefined characters");
	}
	if (!(exit_cnt == 1 && collect_cnt >= 1 && spawn_cnt == 1))
		log_map_file_validity(
			lines,
			"The number of entities in the map doesn\'t meet the requirements");
}

int	search(t_map map, t_map visited, int x, int y)
{
	int	res;

	if (!(
			in_range(map.width, map.height, x, y) \
			&& !at(visited, x, y) \
			&& at(map, x, y) != MAP_COMP_WALL))
		return (0);
	set(visited, x, y, 1);
	res = (at(map, x, y) == MAP_COMP_COLLECTIBLE \
		|| at(map, x, y) == MAP_COMP_EXIT_CLOSED);
	res += search(map, visited, x + 1, y);
	res += search(map, visited, x - 1, y);
	res += search(map, visited, x, y + 1);
	res += search(map, visited, x, y - 1);
	return (res);
}

int	reachable_collect(t_map map, t_player player)
{
	t_map	visited;
	int		reachable;

	visited = new_map(map.width, map.height);
	if (!visited.map)
		return (-1);
	reachable = search(map, visited, player.x, player.y);
	free(visited.map);
	return (reachable);
}

void	check_map_validity(t_game game)
{
	int			i;
	t_map		map;

	map = game.map;
	i = -1;
	while (++i < map.width)
	{
		if (!(\
			at(map, i, 0) == MAP_COMP_WALL \
			&& at(map, i, map.height - 1) == MAP_COMP_WALL))
			log_map_validity(map, "All sides should be surrounded by walls");
	}
	i = -1;
	while (++i < map.height)
	{
		if (!(\
			at(map, 0, i) == MAP_COMP_WALL \
			&& at(map, map.width - 1, i) == MAP_COMP_WALL))
			log_map_validity(map, "All sides should be surrounded by walls");
	}
	if (reachable_collect(map, game.player) \
		< game.collectible_cnt + 1)
		log_map_validity(map, "No valid path exists");
}

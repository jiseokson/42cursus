/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:27:11 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 11:52:38 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **lines)
{
	int	height;

	height = 0;
	while (lines[height])
		++height;
	return (height);
}

t_map_comp	chr_to_comp_id(char comp_chr)
{
	if (comp_chr == MAP_COMP_WALL_CHR)
		return (MAP_COMP_WALL);
	else if (comp_chr == MAP_COMP_COLLECTIBLE_CHR)
		return (MAP_COMP_COLLECTIBLE);
	else if (comp_chr == MAP_COMP_EXIT_CHR)
		return (MAP_COMP_EXIT_CLOSED);
	else
		return (MAP_COMP_NULL);
}

void	parse_map(t_game_state *game_state, char **lines)
{
	int	i;
	int	j;

	i = -1;
	game_state->map = new_map(ft_strlen(lines[0]), get_map_height(lines));
	if (!game_state->map.map)
	{
		ft_free_split(lines);
		exit(1);
	}
	while (++i < game_state->map.height)
	{
		j = -1;
		while (++j < game_state->map.width)
		{
			set(game_state->map, j, i, chr_to_comp_id(lines[i][j]));
			if (lines[i][j] == MAP_COMP_PLAYER_CHR)
				game_state->player = (t_player){j, i};
			else if (lines[i][j] == MAP_COMP_EXIT_CHR)
				game_state->exit = (t_vec2){j, i};
			else if (at(game_state->map, j, i) == MAP_COMP_COLLECTIBLE)
				++game_state->collectible_cnt;
		}
	}
}

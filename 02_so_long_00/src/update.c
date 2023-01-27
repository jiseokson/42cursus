/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:48:57 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 13:54:02 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_entity_interaction(t_app *app, t_game_state *game_state)
{	
	if (at(game_state->map, game_state->player.x, game_state->player.y) \
		== MAP_COMP_COLLECTIBLE)
	{
		--game_state->collectible_cnt;
		set(
			game_state->map,
			game_state->player.x,
			game_state->player.y,
			MAP_COMP_NULL);
	}
	else if (at(game_state->map, game_state->player.x, game_state->player.y) \
		== MAP_COMP_EXIT_OPEN)
		app->is_running = 0;
	if (game_state->collectible_cnt == 0)
		set(
			game_state->map,
			game_state->exit.x,
			game_state->exit.y,
			MAP_COMP_EXIT_OPEN
			);
}

void	update(t_app *app, t_game_state *game_state, t_vec2 *game_command)
{
	int	nx;
	int	ny;

	if (game_command->x == 0 && game_command->y == 0)
		return ;
	nx = game_state->player.x + game_command->x;
	ny = game_state->player.y + game_command->y;
	*game_command = (t_vec2){0, 0};
	if (
		!in_range(game_state->map.width, game_state->map.height, nx, ny)
		|| at(game_state->map, nx, ny) == MAP_COMP_WALL
	)
		return ;
	game_state->player.x = nx;
	game_state->player.y = ny;
	++game_state->move_cnt;
	update_entity_interaction(app, game_state);
	ft_printf(
		"[Player] x: %d, y: %d, move_cnt: %d\n",
		game_state->player.x,
		game_state->player.y,
		game_state->move_cnt
		);
}

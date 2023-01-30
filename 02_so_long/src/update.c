/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:48:57 by jison             #+#    #+#             */
/*   Updated: 2023/01/30 11:20:07 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_entity_interaction(t_app *app, t_game *game)
{	
	if (at(game->map, game->player.x, game->player.y) \
		== MAP_COMP_COLLECTIBLE)
	{
		--game->collectible_cnt;
		set(
			game->map,
			game->player.x,
			game->player.y,
			MAP_COMP_NULL);
	}
	else if (at(game->map, game->player.x, game->player.y) \
		== MAP_COMP_EXIT_OPEN)
		app->is_running = 0;
	if (game->collectible_cnt == 0)
		set(
			game->map,
			game->exit.x,
			game->exit.y,
			MAP_COMP_EXIT_OPEN
			);
}

void	update(t_app *app, t_game *game, t_vec2 *game_command)
{
	int	nx;
	int	ny;

	if (game_command->x == 0 && game_command->y == 0)
		return ;
	nx = game->player.x + game_command->x;
	ny = game->player.y + game_command->y;
	*game_command = (t_vec2){0, 0};
	if (
		!in_range(game->map.width, game->map.height, nx, ny)
		|| at(game->map, nx, ny) == MAP_COMP_WALL
	)
		return ;
	game->player.x = nx;
	game->player.y = ny;
	++game->move_cnt;
	update_entity_interaction(app, game);
	ft_printf(
		"[Player] x: %d, y: %d, move_cnt: %d\n",
		game->player.x,
		game->player.y,
		game->move_cnt
		);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:23:55 by jison             #+#    #+#             */
/*   Updated: 2023/01/30 11:20:08 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_entity(t_app *app)
{
	int			i;
	int			j;
	t_map_comp	comp;

	i = -1;
	while (++i < app->game.map.width)
	{
		j = -1;
		while (++j < app->game.map.height)
		{
			comp = at(app->game.map, i, j);
			if (comp == MAP_COMP_EXIT_CLOSED)
				mlx_put_image_to_window(
					app->mlx, app->window, app->asset.exit_closed.image,
					app->asset.tile_size * i, app->asset.tile_size * j);
			else if (comp == MAP_COMP_EXIT_OPEN)
				mlx_put_image_to_window(
					app->mlx, app->window, app->asset.exit_open.image,
					app->asset.tile_size * i, app->asset.tile_size * j);
			else if (comp == MAP_COMP_COLLECTIBLE)
				mlx_put_image_to_window(
					app->mlx, app->window, app->asset.collectible.image,
					app->asset.tile_size * i, app->asset.tile_size * j);
		}
	}
}

void	render(t_app *app)
{
	mlx_clear_window(app->mlx, app->window);
	mlx_put_image_to_window(
		app->mlx,
		app->window,
		app->asset.background.image,
		0,
		0
		);
	mlx_put_image_to_window(
		app->mlx,
		app->window,
		app->asset.walls.image,
		0,
		0
		);
	render_entity(app);
	mlx_put_image_to_window(
		app->mlx,
		app->window,
		app->asset.player.image,
		app->asset.tile_size * app->game.player.x,
		app->asset.tile_size * app->game.player.y
		);
}

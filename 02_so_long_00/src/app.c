/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:01:07 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 13:54:50 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_app(t_app *app, int ac, char **av)
{
	ft_memset(app, 0, sizeof(t_app));
	app->mlx = mlx_init();
	if (!app->mlx)
		exit(1);
	app->is_running = 1;
	app->game_state = new_game_state(ac, av);
	app->game_command = (t_vec2){0, 0};
	load_asset(app->mlx, &(app->asset), app->game_state.map);
	app->window = mlx_new_window(
			app->mlx,
			app->asset.tile_size * app->game_state.map.width,
			app->asset.tile_size * app->game_state.map.height,
			TITLE
			);
	if (!app->window)
		exit(1);
}

int	game_loop(void *app_ptr)
{
	t_app	*app;

	app = (t_app *)app_ptr;
	if (!app->is_running)
		quit_app(app);
	update(app, &(app->game_state), &(app->game_command));
	render(app);
	return (0);
}

int	quit_app(void *app_ptr)
{
	t_app	*app;

	app = (t_app *)app_ptr;
	free(app->game_state.map.map);
	mlx_destroy_image(app->mlx, app->asset.back.image);
	mlx_destroy_image(app->mlx, app->asset.background.image);
	mlx_destroy_image(app->mlx, app->asset.collectible.image);
	mlx_destroy_image(app->mlx, app->asset.exit_closed.image);
	mlx_destroy_image(app->mlx, app->asset.exit_open.image);
	mlx_destroy_image(app->mlx, app->asset.player.image);
	mlx_destroy_image(app->mlx, app->asset.wall.image);
	mlx_destroy_image(app->mlx, app->asset.walls.image);
	mlx_destroy_window(app->mlx, app->window);
	exit(0);
}

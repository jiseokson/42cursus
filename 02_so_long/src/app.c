/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:01:07 by jison             #+#    #+#             */
/*   Updated: 2023/01/30 13:46:48 by jison            ###   ########.fr       */
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
	app->game = new_game(ac, av);
	app->game_command = (t_vec2){0, 0};
	load_asset(app->mlx, &(app->asset), app->game.map);
	app->window = mlx_new_window(
			app->mlx,
			app->asset.tile_size * app->game.map.width,
			app->asset.tile_size * app->game.map.height,
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
	update(app, &(app->game), &(app->game_command));
	render(app);
	return (0);
}

int	quit_app(void *app_ptr)
{
	t_app	*app;

	app = (t_app *)app_ptr;
	free(app->game.map.map);
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

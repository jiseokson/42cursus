/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:07:55 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 12:05:35 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_app			app;

	build_app(&app, ac, av);
	mlx_hook(app.window, 17, 0, quit_app, &app);
	mlx_key_hook(app.window, key_hook, &app);
	mlx_loop_hook(app.mlx, game_loop, &app);
	mlx_loop(app.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:02:58 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 21:45:45 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_mlx_ptr mlx, t_asset *asset, t_map map)
{
	int	i;
	int	j;

	asset->background = new_surface(
			mlx,
			asset->tile_size * map.width,
			asset->tile_size * map.height
			);
	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			blit(
				asset->background,
				asset->back,
				asset->tile_size * i,
				asset->tile_size * j
				);
			++j;
		}
		++i;
	}
}

void	render_walls(t_mlx_ptr mlx, t_asset *asset, t_map map)
{
	int	i;
	int	j;

	asset->walls = new_surface(
			mlx,
			asset->tile_size * map.width,
			asset->tile_size * map.height
			);
	fill(asset->walls, 0xffffffff);
	i = -1;
	while (++i < map.width)
	{
		j = -1;
		while (++j < map.height)
		{
			if (at(map, i, j) != MAP_COMP_WALL)
				continue ;
			blit(
				asset->walls,
				asset->wall,
				asset->tile_size * i,
				asset->tile_size * j);
		}
	}
}

void	load_sprite(t_mlx_ptr mlx, t_asset *asset)
{
	asset->back = xpm_to_surface(mlx, BACK_FILE);
	asset->wall = xpm_to_surface(mlx, WALL_FILE);
	asset->collectible = xpm_to_surface(mlx, COLLECTIBLE_FILE);
	asset->exit_closed = xpm_to_surface(mlx, EXIT_CLOSED_FILE);
	asset->exit_open = xpm_to_surface(mlx, EXIT_OPEN_FILE);
	asset->player = xpm_to_surface(mlx, PLAYER_FILE);
	asset->tile_size = asset->back.width;
}

void	load_asset(t_mlx_ptr mlx, t_asset *asset, t_map map)
{
	load_sprite(mlx, asset);
	render_background(mlx, asset, map);
	render_walls(mlx, asset, map);
}

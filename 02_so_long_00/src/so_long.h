/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:11:32 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 16:11:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define TITLE				"so_long"
# define BACK_FILE			"res/back.xpm"
# define WALL_FILE			"res/wall.xpm"
# define COLLECTIBLE_FILE	"res/collectible.xpm"
# define EXIT_CLOSED_FILE	"res/exit_closed.xpm"
# define EXIT_OPEN_FILE		"res/exit_open.xpm"
# define PLAYER_FILE		"res/player.xpm"

# define MAP_FILE_EXT	"ber"

# define MAP_COMP_BACK_CHR			'0'
# define MAP_COMP_WALL_CHR			'1'
# define MAP_COMP_COLLECTIBLE_CHR	'C'
# define MAP_COMP_EXIT_CHR			'E'
# define MAP_COMP_PLAYER_CHR		'P'

# define MAP_COMP_NULL			0
# define MAP_COMP_BACK			1
# define MAP_COMP_WALL			2
# define MAP_COMP_COLLECTIBLE	3
# define MAP_COMP_EXIT_CLOSED	4
# define MAP_COMP_EXIT_OPEN		5
# define MAP_COMP_PLAYER		6

# define K_A		0
# define K_S		1
# define K_D		2
# define K_W		13
# define K_ESC		53
# define K_LEFT		123
# define K_RIGHT	124
# define K_DOWN		125
# define K_UP		126

typedef void *	t_mlx_ptr;
typedef void *	t_mlx_window;
typedef void *	t_mlx_image;
typedef int		t_map_comp;

typedef struct s_surface
{
	t_mlx_image	image;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_surface;

typedef struct s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_game_map
{
	int		width;
	int		height;
	char	*map;
}				t_map;

typedef struct s_game_state
{
	t_map			map;
	t_player		player;
	t_vec2			exit;
	int				move_cnt;
	int				collectible_cnt;
}				t_game_state;

typedef struct s_asset
{
	t_surface	back;
	t_surface	background;
	t_surface	wall;
	t_surface	walls;
	t_surface	collectible;
	t_surface	exit_closed;
	t_surface	exit_open;
	t_surface	player;
	int			tile_size;
}				t_asset;

typedef struct s_app
{
	int				is_running;
	t_game_state	game_state;
	t_vec2			game_command;
	t_asset			asset;
	t_mlx_ptr		mlx;
	t_mlx_window	window;
}				t_app;

int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				in_range(int width, int height, int x, int y);
char			*ft_basename(char *path);
void			ft_free_split(char **args);

t_surface		new_surface(t_mlx_ptr mlx, int width, int height);
t_surface		xpm_to_surface(t_mlx_ptr mlx, char *file);
t_surface		blit(t_surface dst, t_surface src, int x, int y);
void			fill(t_surface surface, int color);

t_map			new_map(int width, int height);
t_map_comp		set(t_map map, int x, int y, t_map_comp comp);
t_map_comp		at(t_map map, int x, int y);

void			log_map_file_validity(char **lines, char *message);
void			log_map_validity(t_map map, char *message);
void			check_map_file_validity(char **lines);
void			check_map_validity(t_game_state game_state);

void			parse_map(t_game_state *game_state, char **lines);
void			load_asset(t_mlx_ptr mlx, t_asset *asset, t_map map);
t_game_state	new_game_state(int ac, char **av);

int				key_hook(int keycode, void *app_ptr);
void			build_app(t_app *app, int ac, char **av);
int				quit_app(void *app);
int				game_loop(void *app_ptr);
void			update(t_app *app, t_game_state *game_state, t_vec2 *gc);
void			render(t_app *app);

#endif

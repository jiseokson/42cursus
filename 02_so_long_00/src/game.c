/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:02:27 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 12:03:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_file_fd(int ac, char **av)
{
	int		fd;
	char	*path;
	char	*base;

	if (ac != 2)
	{
		ft_printf("Usage: so_long *.ber\n");
		exit(1);
	}
	path = av[1];
	base = ft_basename(path);
	if (!base || ft_strncmp(base, MAP_FILE_EXT, ft_strlen(MAP_FILE_EXT)))
	{
		ft_printf("%s: File must have a .ver extension\n", TITLE);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(TITLE);
		exit(1);
	}
	return (fd);
}

char	*get_map_file_content(int fd)
{
	char	*buffer;
	char	*temp1;
	char	*temp2;

	buffer = ft_strdup("");
	if (!buffer)
		exit(1);
	while (1)
	{
		temp1 = get_next_line(fd);
		if (!temp1)
			break ;
		temp2 = ft_strjoin(buffer, temp1);
		free(buffer);
		free(temp1);
		buffer = temp2;
		if (!buffer)
			exit(1);
	}
	return (buffer);
}

t_game_state	new_game_state(int ac, char **av)
{
	t_game_state	game_state;
	char			*buffer;
	char			**lines;

	ft_memset(&game_state, 0, sizeof(game_state));
	buffer = get_map_file_content(get_file_fd(ac, av));
	lines = ft_split(buffer, '\n');
	free(buffer);
	check_map_file_validity(lines);
	parse_map(&game_state, lines);
	ft_free_split(lines);
	check_map_validity(game_state);
	game_state.move_cnt = 0;
	return (game_state);
}

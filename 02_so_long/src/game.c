/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:02:27 by jison             #+#    #+#             */
/*   Updated: 2023/01/30 13:45:11 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_file_fd(int ac, char **av)
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
	char	*line;
	char	*temp;

	buffer = ft_strdup("");
	if (!buffer)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 1 && !ft_strncmp(line, "\n", 1))
			log_empty_line(buffer, line, "Empty line in map file");
		temp = ft_strjoin(buffer, line);
		free(buffer);
		free(line);
		buffer = temp;
		if (!buffer)
		{
			close(fd);
			exit(1);
		}
	}
	return (buffer);
}

t_game	new_game(int ac, char **av)
{
	t_game	game;
	char	*buffer;
	char	**lines;
	int		fd;

	ft_memset(&game, 0, sizeof(game));
	fd = get_map_file_fd(ac, av);
	buffer = get_map_file_content(fd);
	close(fd);
	lines = ft_split(buffer, '\n');
	free(buffer);
	check_map_file_validity(lines);
	parse_map(&game, lines);
	ft_free_split(lines);
	check_map_validity(game);
	game.move_cnt = 0;
	return (game);
}

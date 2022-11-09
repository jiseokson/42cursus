/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:05:46 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 23:27:19 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "io.h"
#include "tail.h"
#include "ft_print.h"

char	*get_tail(char *content, int offset)
{
	int		line;
	char	*tail;

	line = 10;
	tail = content;
	while (*tail)
		++tail;
	if (offset != -1)
	{
		while (offset--)
			--tail;
		return (tail);
	}
	else
	{
		while (tail != content)
		{
			if (*tail == '\n')
				--line;
			if (line == -1)
				return (tail + 1);
			--tail;
		}
		return (tail);
	}
}

int	print_file_tail(int fd, int offset)
{
	char	*content;
	char	*tail;

	content = read_content(fd);
	tail = get_tail(content, offset);
	ft_fprint(1, tail);
	free(content);
	return (0);
}

int	files(char *program_name, int ac, char **av, int offset)
{
	int	i;
	int	fd;
	int	exit_code;
	int	new_line_flag;

	i = -1;
	exit_code = 0;
	new_line_flag = 0;
	while (++i < ac)
	{
		fd = open_file(av[i]);
		if (fd < 0)
		{
			ft_print_file_error(program_name, av[i], strerror(errno));
			exit_code = 1;
			continue ;
		}
		if (new_line_flag)
			ft_fprint(1, "\n");
		ft_print_file_name(av[i]);
		print_file_tail(fd, offset);
		close_file(fd);
		new_line_flag = 1;
	}
	return (exit_code);
}

int	run(char *program_name, int ac, char **av, int offset)
{
	int	exit_code;

	exit_code = 0;
	if (ac == 0)
		print_file_tail(1, offset);
	else
		exit_code = files(program_name, ac, av, offset);
	return (exit_code);
}

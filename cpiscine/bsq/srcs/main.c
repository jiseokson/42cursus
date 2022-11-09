/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:43:40 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/19 19:24:36 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"
#include "ft_print.h"
#include "io.h"
#include "valid.h"

int	handle_arg(char *path)
{
	int		fd;
	char	*buffer;

	fd = open_file(path);
	if (fd < 0)
	{
		ft_fprint(2, "map error\n");
		return (0);
	}
	buffer = read_content(fd);
	if (close_file(fd) < 0)
	{
		free(buffer);
		return (0);
	}
	if (!is_valid(buffer))
	{
		ft_fprint(2, "map error\n");
		free(buffer);
		return (0);
	}
	bsq(buffer);
	free(buffer);
	return (0);
}

int	handle_stdin(void)
{
	char	*buffer;

	buffer = read_content(0);
	if (!is_valid(buffer))
	{
		ft_fprint(2, "map error\n");
		free(buffer);
		return (0);
	}
	bsq(buffer);
	free(buffer);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		handle_stdin();
	while (--ac)
	{
		handle_arg(*(++av));
		if (ac > 1)
			ft_fprint(1, "\n");
	}
	return (0);
}

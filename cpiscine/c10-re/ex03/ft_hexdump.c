/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:49:34 by jison             #+#    #+#             */
/*   Updated: 2022/10/19 21:52:50 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "io.h"
#include "ft_string.h"
#include "ft_print.h"
#include "print_dump.h"

int	get_option(int ac, char **av, char *option)
{
	if (ac >= 2 && !ft_strcmp(av[1], option))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*program_name;
	char	*content;
	int		c_flag;
	int		fd;

	program_name = basename(av[0]);
	c_flag = get_option(ac, av, "-C");
	if (c_flag)
		++av;
	while (*(++av))
	{
		fd = open_file(*av);
		if (fd < 0)
		{
			ft_print_file_error(program_name, *av, strerror(errno));
			continue ;
		}
		content = read_content(fd);
		if (c_flag)
			print_dump_ascii(content, ft_strlen(content));
		else
			print_dump(content, sizeof(content));
		free(content);
	}
	return (0);
}

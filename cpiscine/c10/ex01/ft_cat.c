/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:37:55 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 19:28:07 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libgen.h>
#include <errno.h>

#define BUFFER_SIZE (1024)

int		open_file(char *path);
int		close_file(int fd);
int		read_content(int fd, char *buffer, int buffer_size);
void	ft_print(char *str);
void	ft_print_error(char *program_name, char *path, char *error);

void	print_content(int fd)
{
	char	buffer[BUFFER_SIZE];

	while (read_content(fd, buffer, BUFFER_SIZE))
		ft_print(buffer);
}

int	main(int argc, char **argv)
{
	char	*program_name;
	int		fd;
	int		exit_code;

	program_name = basename(*argv);
	exit_code = 0;
	if (argc == 1)
		print_content(0);
	while (--argc)
	{
		fd = open_file(*(++argv));
		if (fd < 0)
		{
			ft_print_error(program_name, *argv, strerror(errno));
			exit_code = 1;
			continue ;
		}
		print_content(fd);
		if (close_file(fd) < 0)
		{
			ft_print_error(program_name, *argv, strerror(errno));
			exit_code = 1;
		}
	}
	return (exit_code);
}

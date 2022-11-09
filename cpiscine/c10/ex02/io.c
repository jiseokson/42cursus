/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:45:43 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 23:28:52 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_string.h"

#define BUFFER_SIZE (4096)

int	open_file(char *path)
{
	if (!ft_strcmp(path, "-"))
		return (0);
	return (open(path, O_RDONLY));
}

int	close_file(int fd)
{
	if (fd == 0)
		return (0);
	return (close(fd));
}

char	*new_content(char *content, char *buffer)
{
	char	*ret;

	ret = \
	(char *)malloc(sizeof(char) * (ft_strlen(content) + ft_strlen(buffer) + 1));
	ret[0] = '\0';
	ft_strcat(ret, content);
	ft_strcat(ret, buffer);
	free(content);
	free(buffer);
	return (ret);
}

int	read_buffer(int fd, char *buffer, int buffer_size)
{
	int	readed_byte;

	readed_byte = read(fd, buffer, buffer_size - 1);
	buffer[readed_byte] = '\0';
	return (readed_byte > 0);
}

char	*read_content(int fd)
{
	char	*content;
	char	*buffer;

	content = (char *)malloc(sizeof(char));
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	content[0] = '\0';
	while (read_buffer(fd, buffer, BUFFER_SIZE))
	{
		content = new_content(content, buffer);
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	}
	free(buffer);
	return (content);
}

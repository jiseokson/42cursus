/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:11:42 by jison             #+#    #+#             */
/*   Updated: 2022/11/18 15:32:21 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_iobuffer	io[GNL_OPEN_MAX + 1];
	char				*line;

	if (!(0 <= fd && fd <= GNL_OPEN_MAX))
		return (NULL);
	if (read_line(fd, io + fd) <= 0)
	{
		clear_io_buffer(io + fd);
		return (NULL);
	}
	line = get_line_(io + fd);
	if (!line)
	{
		clear_io_buffer(io + fd);
		return (NULL);
	}
	return (line);
}

ssize_t	read_line(int fd, t_iobuffer *io)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	readed;

	if (!io)
	{
		io->chunk = NULL;
		io->size = 0;
		io->block_cnt = 0;
	}
	while (!io->chunk || !ft_memchr(io->chunk, '\n', io->size))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (-1);
		else if (readed == 0)
			break ;
		if (!concat_chunk(io, buffer, readed))
			return (-1);
	}
	return (io->size);
}

int	concat_chunk(t_iobuffer *io, char *buffer, ssize_t readed)
{
	char	*new_chunk;

	if (io->size + readed > io->block_cnt * BLOCK_SIZE)
	{
		while (io->size + readed > io->block_cnt * BLOCK_SIZE)
			++io->block_cnt;
		new_chunk = (char *)malloc(BLOCK_SIZE * io->block_cnt * sizeof(char));
		if (!new_chunk)
			return (0);
		ft_memcpy(new_chunk, io->chunk, io->size);
		if (io->chunk)
			free(io->chunk);
		io->chunk = new_chunk;
	}
	ft_memcpy(io->chunk + io->size, buffer, readed);
	io->size += readed;
	return (1);
}

char	*get_line_(t_iobuffer *io)
{
	char	*end;
	char	*line;
	ssize_t	line_len;

	end = ft_memchr(io->chunk, '\n', io->size);
	if (!end)
		line_len = io->size;
	else
		line_len = (end - io->chunk) + 1;
	line = ft_substr(io->chunk, 0, line_len);
	if (!line)
		return (NULL);
	ft_memcpy(io->chunk, io->chunk + line_len, io->size - line_len);
	io->size -= line_len;
	return (line);
}

void	clear_io_buffer(t_iobuffer *io)
{
	if (io->chunk)
	{
		free(io->chunk);
		io->chunk = NULL;
	}
	io->size = 0;
	io->block_cnt = 0;
}
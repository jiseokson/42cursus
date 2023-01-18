/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:42:48 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 14:59:37 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BLOCK_SIZE 4096
# define GNL_OPEN_MAX 256
# define BUFFER_SIZE 100

typedef struct s_iobuffer
{
	char	*chunk;
	ssize_t	size;
	ssize_t	block_cnt;
}				t_iobuffer;

char	*get_next_line(int fd);

ssize_t	read_line(int fd, t_iobuffer *io);
int		concat_chunk(t_iobuffer *io, char *buffer, ssize_t readed);
char	*get_line_(t_iobuffer *io);
void	clear_io_buffer(t_iobuffer *io);

char	*ft_gnl_substr(const char *s, unsigned int start, ssize_t len);

#endif
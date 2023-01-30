/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:12:07 by jison             #+#    #+#             */
/*   Updated: 2022/11/19 12:35:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define BLOCK_SIZE 4096
# define GNL_OPEN_MAX 256

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

void	*ft_memcpy(void *dst, const void *src, ssize_t n);
void	*ft_memchr(const void *s, int c, ssize_t n);
char	*ft_substr(const char *s, unsigned int start, ssize_t len);

#endif
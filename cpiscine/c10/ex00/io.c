/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:45:43 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 18:40:28 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strcmp(char *s1, char *s2);

int	open_file(char *path)
{
	if (! ft_strcmp(path, "-"))
		return (0);
	return (open(path, O_RDONLY));
}

int	close_file(int fd)
{
	if (fd == 0)
		return (0);
	return (close(fd));
}

int	read_content(int fd, char *buffer, int buffer_size)
{
	int	readed_bytes;

	readed_bytes = read(fd, buffer, buffer_size - 1);
	buffer[readed_bytes] = '\0';
	return (readed_bytes > 0);
}

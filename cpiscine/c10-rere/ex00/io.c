/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:45:43 by jison             #+#    #+#             */
/*   Updated: 2022/10/20 15:56:40 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strcmp(char *s1, char *s2);
void	ft_fprint(int fd, char *str);

int	open_file(char *path)
{
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
	if (readed_bytes < 0)
	{
		ft_fprint(2, "Cannot read file.\n");
		return (0);
	}
	return (readed_bytes > 0);
}

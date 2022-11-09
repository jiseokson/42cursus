/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:59:47 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 18:04:23 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "io.h"

int	open_file(char *path, int *fd_len, int *fd_line)
{
	*fd_len = open(path, O_RDONLY);
	*fd_line = open(path, O_RDONLY);
	if (*fd_len < 0 || *fd_line < 0)
		return (0);
	return (1);
}

void	close_file(int fd_len, int fd_line)
{
	close(fd_len);
	close(fd_line);
}

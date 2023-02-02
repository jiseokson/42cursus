/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:15:05 by jison             #+#    #+#             */
/*   Updated: 2023/02/02 18:13:02 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_duplex_pipe
{
	int	fds0[2];
	int	fds1[2];
}				t_duplex_pipe;

int		duplex_pipe(t_duplex_pipe *dp);
void	parent_pipe(t_duplex_pipe *dp, int fd[]);
void	child_pipe(t_duplex_pipe *dp, int fd[]);
int		close_duplex_pipe(t_duplex_pipe *dp);

#endif

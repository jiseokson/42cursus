/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplex_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:13:15 by jison             #+#    #+#             */
/*   Updated: 2023/02/02 18:30:04 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	duplex_pipe(t_duplex_pipe *dp)
{
	ft_memset(dp, -1, sizeof(t_duplex_pipe));
	if (pipe(dp->fds0) == -1 || pipe(dp->fds1) == -1)
		return (-1);
	return (0);
}

void	parent_pipe(t_duplex_pipe *dp, int fd[])
{
	fd[0] = dp->fds1[0];
	fd[1] = dp->fds0[1];
}

void	child_pipe(t_duplex_pipe *dp, int fd[])
{
	fd[0] = dp->fds0[0];
	fd[1] = dp->fds1[1];
}

int	close_duplex_pipe(t_duplex_pipe *dp)
{
	int	has_error_case;

	has_error_case = 0;
	if (dp->fds0[0] != -1)
		has_error_case = (has_error_case || close(dp->fds0[0]) == -1);
	if (dp->fds0[1] != -1)
		has_error_case = (has_error_case || close(dp->fds0[1]) == -1);
	if (dp->fds1[0] != -1)
		has_error_case = (has_error_case || close(dp->fds1[0]) == -1);
	if (dp->fds1[1] != -1)
		has_error_case = (has_error_case || close(dp->fds1[1]) == -1);
	if (has_error_case)
		return (-1);
	return (0);
}

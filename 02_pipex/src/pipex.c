/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:50:47 by jison             #+#    #+#             */
/*   Updated: 2023/02/02 18:31:26 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t			child_pid;
	int				status;
	t_duplex_pipe	dp;
	int				fds[2];
	char			*buffer;

	if (duplex_pipe(&dp) == -1)
	{
		perror("duplex_pipe()");
		close_duplex_pipe(&dp);
		exit(EXIT_FAILURE);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork()");
		close_duplex_pipe(&dp);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		// Child
		child_pipe(&dp, fds);
		ft_fprintf(fds[1], "This is from child(%d)\n", getpid());
		buffer = get_next_line(fds[0]);
		sleep(1);
		ft_printf("Child received: %s", buffer);
		free(buffer);
		close_duplex_pipe(&dp);
		return (0);
	}
	else
	{
		// Parent
		ft_printf("Parent(%d) create child process(%d)\n", getpid(), child_pid);
		parent_pipe(&dp, fds);
		ft_fprintf(fds[1], "This is from parent(%d)\n", getpid());
		buffer = get_next_line(fds[0]);
		ft_printf("Parent received: %s", buffer);
		free(buffer);
		close_duplex_pipe(&dp);
		wait(&status);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:50:47 by jison             #+#    #+#             */
/*   Updated: 2023/02/09 19:38:41 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(int fds[], char *limiter)
{
	pid_t	pid;
	char	*line;
	size_t	limiter_len;

	pid = fork();
	if (pid == 0)
		pipex_log("fork()");
	else if (pid == 0)
	{
		close(fds[0]);
		limiter_len = ft_strlen(limiter);
		while (1)
		{
			ft_printf("heredoc> ");
			line = get_next_line(STDIN_FILENO);
			if (!line)
				return ;
			if (
				ft_strlen(line) == limiter_len + 1 && line[limiter_len] == '\n'
				&& !ft_strncmp(line, limiter, limiter_len))
				break ;
			ft_fprintf(fds[1], "%s", line);
			free(line);
		}
		free(line);
	}
}

void	open_output_file(t_cmd_info *cmd_info, int fds[])
{
	if (!cmd_info->outfile)
	{
		if (pipe(fds) == -1)
			pipex_log("pipe()");
	}
	else
	{
		fds[1] = open(
				cmd_info->outfile,
				O_CREAT | O_TRUNC | O_WRONLY,
				cmd_info->outfile_perm);
		if (fds[1] == -1)
			pipex_log(cmd_info->outfile);
		fds[0] = dup(fds[1]);
	}
}

void	exec_command(t_cmd_info *cmd_info, int fds[][2], int cmd_no)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		pipex_log("fork()");
	else if (pid == 0)
	{
		dup2(fds[cmd_no % 2][0], STDIN_FILENO);
		close(fds[cmd_no % 2][1]);
		close(fds[!(cmd_no % 2)][0]);
		dup2(fds[!(cmd_no % 2)][1], STDOUT_FILENO);
		execve(cmd_info->path, cmd_info->argv, NULL);
	}
	close(fds[cmd_no % 2][0]);
	close(fds[cmd_no % 2][1]);
}

void	wait_all(int cmd_cnt)
{
	int		i;
	int		status;
	pid_t	pid;

	i = -1;
	while (++i < cmd_cnt)
		pid = wait(&status);
}

void	pipex_job(t_cmd_info_list cmd_info_list)
{
	int		fds[2][2];
	int		i;

	fds[0][0] = open(((t_cmd_info *)cmd_info_list.head->content)->infile, O_RDONLY);
	fds[0][1] = dup(STDOUT_FILENO);
	i = -1;
	while (++i < cmd_info_list.size)
	{
		open_output_file(cmd_info_list.cur->content, fds[!(i % 2)]);
		exec_command(cmd_info_list.cur->content, fds, i);
		ft_nextlst(&cmd_info_list.cur);
	}
	close(fds[cmd_info_list.size % 2][0]);
	close(fds[cmd_info_list.size % 2][1]);
	wait_all(cmd_info_list.size);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd_info_list	cmd_info_list;

	(void)envp;
	cmd_info_list = new_cmd_info_list(argc - 3, argv + 2);
	((t_cmd_info *)cmd_info_list.head->content)->infile = argv[1];
	((t_cmd_info *)cmd_info_list.head->content)->infile_limiter = NULL;
	((t_cmd_info *)cmd_info_list.head->content)->infile_perm = -1;
	((t_cmd_info *)ft_lstlast(cmd_info_list.head)->content)->outfile = argv[argc - 1];
	((t_cmd_info *)ft_lstlast(cmd_info_list.head)->content)->outfile_perm = 0644;
	pipex_job(cmd_info_list);
	delete_cmd_info_list(cmd_info_list);
	system("leaks pipex");
	return (0);
}

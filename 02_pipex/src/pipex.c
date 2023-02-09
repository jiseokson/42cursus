/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:50:47 by jison             #+#    #+#             */
/*   Updated: 2023/02/09 18:46:59 by jison            ###   ########.fr       */
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

void	open_init_file(int fds[][2], char *input_file, char *limiter)
{
	if (ft_strlen(input_file) == ft_strlen("here_doc")
		&& ft_strncmp(input_file, "here_doc", 8))
	{
		if (pipe(fds[0]) == -1)
			pipex_log("pipe()");
		heredoc(fds[0], limiter);
	}
	else
	{
		fds[0][0] = open(input_file, O_RDONLY);
		if (fds[0][0] == -1)
			pipex_log(input_file);
		fds[0][1] = dup(fds[0][0]);
	}
}

void	open_output_file(
	int cmd_cnt, int fds[][2], char *output_file, int outfile_mode, int cmd_no)
{
	if (cmd_no + 1 < cmd_cnt)
	{
		if (pipe(fds[!(cmd_no % 2)]) == -1)
			pipex_log("pipe()");
	}
	else
	{
		fds[!(cmd_no % 2)][1] = open(
				output_file, O_CREAT | O_TRUNC | O_WRONLY, outfile_mode);
		if (fds[!(cmd_no % 2)][1] == -1)
			pipex_log(output_file);
		fds[!(cmd_no % 2)][0] = dup(fds[0][1]);
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

void	pipex_job(
	t_cmd_info_list cmd_info_list,
	char *input_file, char *limiter, char *output_file, int outfile_mode)
{
	int		fds[2][2];
	int		i;

	open_init_file(fds, input_file, limiter);
	i = -1;
	while (++i < cmd_info_list.size)
	{
		open_output_file(cmd_info_list.size, fds, output_file, outfile_mode, i);
		exec_command(cmd_info_list.cur->content, fds, i);
		close(fds[i % 2][0]);
		close(fds[i % 2][1]);
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
	pipex_job(cmd_info_list, "input.txt", NULL, "output.txt", 0644);
	delete_cmd_info_list(cmd_info_list);
	system("leaks pipex");
	return (0);
}

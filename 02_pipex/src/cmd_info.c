/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:15:42 by jison             #+#    #+#             */
/*   Updated: 2023/02/09 17:28:37 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd_name)
{
	(void)cmd_name;
	return (ft_strdup("/bin/cat"));
}

char	**make_argv(char *cmd_string)
{
	return (ft_split(cmd_string, ' '));
}

t_cmd_info	*new_cmd_info(char *cmd_string)
{
	t_cmd_info	*cmd_info;

	cmd_info = (t_cmd_info *)malloc(sizeof(t_cmd_info));
	if (!cmd_info)
		pipex_log("Failed to allocate command information");
	cmd_info->path = find_path(cmd_string);
	cmd_info->argv = make_argv(cmd_string);
	return (cmd_info);
}

void	delete_cmd_info(void *cmd_info_ptr)
{
	t_cmd_info	*cmd_info;

	cmd_info = (t_cmd_info *)cmd_info_ptr;
	free(cmd_info->path);
	ft_free_split(cmd_info->argv);
	free(cmd_info);
}

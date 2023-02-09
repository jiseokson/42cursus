/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:25:34 by jison             #+#    #+#             */
/*   Updated: 2023/02/09 18:32:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_info_list	new_cmd_info_list(int cmd_cnt, char **cmdv)
{
	t_cmd_info_list	cmd_info_list;
	t_list			*temp;
	int				i;

	ft_memset(&cmd_info_list, 0, sizeof(t_cmd_info_list));
	i = -1;
	while (++i < cmd_cnt)
	{
		temp = ft_lstnew(new_cmd_info(cmdv[i]));
		if (!temp)
			pipex_log("Failed to allocate command information");
		ft_lstadd_back(&cmd_info_list.head, temp);
	}
	cmd_info_list.cur = cmd_info_list.head;
	cmd_info_list.size = cmd_cnt;
	return (cmd_info_list);
}

void	delete_cmd_info_list(t_cmd_info_list cmd_info_list)
{
	ft_lstclear(&cmd_info_list.head, delete_cmd_info);
}

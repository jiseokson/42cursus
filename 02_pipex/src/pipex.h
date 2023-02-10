/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:15:05 by jison             #+#    #+#             */
/*   Updated: 2023/02/10 15:43:44 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define PROGRAM_NAME	"pipex"

typedef struct s_cmd_info
{
	char	*path;
	char	**argv;
	char	*infile;
	char	*infile_limiter;
	char	*outfile;
	int		infile_perm;
	int		outfile_perm;
}				t_cmd_info;

typedef struct s_cmd_info_list
{
	t_list	*head;
	t_list	*tail;
	t_list	*cur;
	int		size;
}				t_cmd_info_list;

void			ft_free_split(char **args);
void			ft_nextlst(t_list **lst);

void			pipex_log(char *message);

t_cmd_info		*new_cmd_info(char *cmd_string);
void			delete_cmd_info(void *cmd_info_ptr);
t_cmd_info_list	new_cmd_info_list(int cmd_cnt, char **cmdv);
void			delete_cmd_info_list(t_cmd_info_list cmd_info_list);

#endif

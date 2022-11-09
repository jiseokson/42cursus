/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:51:03 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 20:41:42 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DICT_H
# define PARSE_DICT_H

# include "dict_list.h"

int		parse_dict(t_dict_list *dict_list, char *path);
int		append_pair(t_dict_list *dict_list, char *line);
int		count_colon(char *line);
int		is_empty_line(char *line);
char	*get_value(char *str);
char	*get_key(char *str);
int		is_empty(char c);
void	increaser(int *a, int *b);
int		check_double_key(t_dict_list *dict_list);

#endif

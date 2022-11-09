/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:25:17 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 19:04:09 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_LIST_H
# define DICT_LIST_H

typedef struct s_dict_node
{
	char				*key;
	char				*value;
	struct s_dict_node	*next;
}				t_dict_node;

typedef struct s_dict_list
{
	struct s_dict_node	*head;
}				t_dict_list;

t_dict_list	*new_dict_list(void);
t_dict_node	*new_dict_node(char *key, char *value);
void		append(t_dict_list *dict_list, t_dict_node *node);
t_dict_node	*search(t_dict_list *dict_list, char *key);
t_dict_node	*search_by_uint(t_dict_list *dict_list, int key);
t_dict_node	*search_by_block_index(t_dict_list *dict_list, int block_index);
void		free_dict_list(t_dict_list *dict_list);

#endif

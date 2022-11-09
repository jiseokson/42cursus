/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:29:49 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 21:19:56 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict_list.h"
#include "ft_string.h"
#include "parse.h"

t_dict_list	*new_dict_list(void)
{
	t_dict_list	*dict_list;

	dict_list = (t_dict_list *)malloc(sizeof(t_dict_list));
	if (! dict_list)
		return (0);
	dict_list -> head = 0;
	return (dict_list);
}

t_dict_node	*new_dict_node(char *key, char *value)
{
	t_dict_node	*node;

	node = (t_dict_node *)malloc(sizeof(t_dict_node));
	if (! node)
		return (0);
	node -> key = key;
	node -> value = value;
	node -> next = 0;
	return (node);
}

void	append(t_dict_list *dict_list, t_dict_node *node)
{
	if (! dict_list -> head)
		dict_list -> head = node;
	else
	{
		node -> next = dict_list -> head;
		dict_list -> head = node;
	}
}

void	free_dict_node(t_dict_node *node)
{
	if (! node)
		return ;
	free_dict_node(node -> next);
	free(node -> key);
	free(node -> value);
	free(node);
}

void	free_dict_list(t_dict_list *dict_list)
{
	free_dict_node(dict_list -> head);
	free(dict_list);
}

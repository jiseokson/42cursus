/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_list_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:01:51 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 19:18:19 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict_list.h"
#include "ft_string.h"
#include "parse.h"

t_dict_node	*search(t_dict_list *dict_list, char *key)
{
	t_dict_node	*cur;

	cur = dict_list -> head;
	while (cur)
	{
		if (! ft_strcmp(cur -> key, key))
			return (cur);
		cur = cur -> next;
	}
	return (0);
}

t_dict_node	*search_by_uint(t_dict_list	*dict_list, int key)
{
	t_dict_node	*cur;

	cur = dict_list -> head;
	while (cur)
	{
		if (ft_atoi(cur -> key) == key)
			return (cur);
		cur = cur -> next;
	}
	return (0);
}

t_dict_node	*search_by_block_index(t_dict_list *dict_list, int block_index)
{
	char		*block_key;
	t_dict_node	*cur;

	block_key = (char *)malloc(sizeof(char) * (3 * block_index + 2));
	if (! block_key)
		return (0);
	ft_strcpy(block_key, "1");
	while (block_index--)
		ft_strcat(block_key, "000");
	cur = dict_list -> head;
	while (cur)
	{
		if (! ft_strcmp(cur -> key, block_key))
		{
			free(block_key);
			return (cur);
		}
		cur = cur -> next;
	}
	free(block_key);
	return (0);
}

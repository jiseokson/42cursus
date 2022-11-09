/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:40:22 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 20:51:48 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_dict.h"
#include "ft_string.h"

int	count_node(t_dict_list *dict_list)
{
	int			ret;
	t_dict_node	*cur;

	ret = 0;
	cur = dict_list->head;
	while (cur)
	{
		++ret;
		cur = cur->next;
	}
	return (ret);
}

t_dict_node	*at(t_dict_list *dict_list, int n)
{
	t_dict_node	*cur;

	cur = dict_list->head;
	while (n--)
		cur = cur->next;
	return (cur);
}

int	check_double_key(t_dict_list *ls)
{
	int	size;
	int	i;
	int	j;

	size = count_node(ls);
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (! ft_strcmp(at(ls, i)->key, at(ls, j)->key))
				return (0);
		}
	}
	return (1);
}

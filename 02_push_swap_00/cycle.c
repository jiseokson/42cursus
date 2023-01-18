/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:12:30 by jison             #+#    #+#             */
/*   Updated: 2023/01/16 13:44:10 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cycle	*new_cycle(void)
{
	t_cycle	*list;

	list = (t_cycle *)malloc(sizeof(t_cycle));
	if (!list)
		return (NULL);
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
	return (list);
}

t_cycle_node	*new_cycle_node(int value)
{
	t_cycle_node	*node;

	node = (t_cycle_node *)malloc(sizeof(t_cycle_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

void	free_cycle(t_cycle *list)
{
	if (!list)
		return ;
	while (list->size > 0)
		free(pop(list));
	free(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:43:51 by jison             #+#    #+#             */
/*   Updated: 2023/01/16 13:44:16 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_cycle *list, t_cycle_node *node)
{
	if (!list || !node)
		return ;
	if (list->size == 0)
	{
		node->next = node;
		node->prev = node;
		list->top = node;
		list->bottom = node;
	}
	else
	{
		node->next = list->bottom;
		node->prev = list->top;
		list->top->next = node;
		list->bottom->prev = node;
		list->top = node;
	}
	++(list->size);
}

t_cycle_node	*pop(t_cycle *list)
{
	t_cycle_node	*node;

	if (!list)
		return (NULL);
	node = list->top;
	if (list->size == 1)
	{
		list->top = NULL;
		list->bottom = NULL;
		--(list->size);
	}
	else if (list->size > 1)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		list->top = list->top->prev;
		--(list->size);
	}
	return (node);
}

void	rotate(t_cycle *list)
{
	if (!list)
		return ;
	if (list->size <= 1)
		return ;
	list->top = list->top->prev;
	list->bottom = list->bottom->prev;
}

void	r_rotate(t_cycle *list)
{
	if (!list)
		return ;
	if (list->size <= 1)
		return ;
	list->top = list->top->next;
	list->bottom = list->bottom->next;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:09:38 by jison             #+#    #+#             */
/*   Updated: 2023/01/16 13:41:31 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_dist(t_cycle_node *lo, t_cycle_node *hi)
{
	int	dist;

	dist = 0;
	while (lo != hi)
	{
		lo = lo->next;
		++dist;
	}
	return (dist + 1);
}

t_range	node_range(t_cycle_node *lo, t_cycle_node *hi)
{
	return ((t_range){lo, hi, node_dist(lo, hi)});
}

int	get_pivot(t_cycle *cycle, int cnt)
{
	t_cycle_node	*cur;
	int				*arr;
	int				i;
	int				pivot;

	cur = cycle->top;
	arr = (int *)malloc(sizeof(int) * cnt);
	if (!arr)
		return (cycle->top->value);
	i = 0;
	while (i < cnt)
	{
		arr[i] = cur->value;
		cur = cur->prev;
		++i;
	}
	quick_sort(arr, 0, cnt - 1);
	pivot = arr[cnt / 3];
	free(arr);
	return (pivot);
}

int	is_sorted(t_range range)
{
	t_cycle_node	*lo;

	lo = range.lo;
	while (lo != range.hi)
	{
		if (lo->value < lo->next->value)
			return (FALSE);
		lo = lo->next;
	}
	return (TRUE);
}

void	range_to_top(t_cycle *pair[], t_range range)
{
	int	r_cnt;
	int	rr_cnt;

	r_cnt = node_dist(range.hi, pair[CYCLE_A]->top) - 1;
	rr_cnt = node_dist(pair[CYCLE_A]->bottom, range.hi);
	if (r_cnt < rr_cnt)
		adjust_n(pair, CMD_RA, r_cnt);
	else
		adjust_n(pair, CMD_RRA, rr_cnt);
}

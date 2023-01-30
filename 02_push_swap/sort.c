/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:53:06 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 15:58:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_quads(t_cycle *a, t_range quads[])
{
	int				par_cnt;
	int				cnt;
	t_cycle_node	*cur;

	par_cnt = 0;
	cur = a->top;
	while (par_cnt < 4)
	{
		if (quads[par_cnt].size > 0)
		{
			quads[par_cnt].hi = cur;
			cnt = quads[par_cnt].size;
			while (cnt--)
				cur = cur->prev;
			quads[par_cnt].lo = cur->next;
		}
		cur = cur->prev;
		++par_cnt;
	}
}

void	pass_to(int to_id, t_cycle *pair[], t_range range, t_range doubles[])
{
	int	from_id;
	int	pivot;

	from_id = 1 - to_id;
	pivot = get_pivot(pair[from_id], range.size);
	while (range.size--)
	{
		if (pair[from_id]->top->value < pivot)
		{
			adjust(pair, get_cmd_id(to_id, CMD_TYPE_P));
			adjust(pair, get_cmd_id(to_id, CMD_TYPE_R));
			++doubles[0].size;
		}
		else if (pair[from_id]->top->value > pivot)
		{
			adjust(pair, get_cmd_id(to_id, CMD_TYPE_P));
			++doubles[1].size;
		}
		else
			adjust(pair, get_cmd_id(from_id, CMD_TYPE_R));
	}
	adjust(pair, get_cmd_id(from_id, CMD_TYPE_RR));
	adjust(pair, get_cmd_id(to_id, CMD_TYPE_P));
}

void	partition(t_cycle *pair[], t_range range, t_range quads[])
{
	t_range	doubles[2];

	ft_memset(doubles, 0, sizeof(doubles));
	pass_to(CYCLE_B, pair, range, doubles);
	if (doubles[1].size > 0)
	{
		adjust(pair, CMD_RB);
		pass_to(CYCLE_A, pair, doubles[1], quads + 2);
		adjust_n(pair, CMD_RRA, quads[2].size);
		adjust(pair, CMD_RRB);
	}
	adjust(pair, CMD_PA);
	if (doubles[0].size > 0)
	{
		pass_to(CYCLE_A, pair, doubles[0], quads);
		adjust_n(pair, CMD_RRA, quads[0].size);
	}
	set_quads(pair[CYCLE_A], quads);
}

void	mysort(t_cycle *pair[], t_range range)
{
	t_range	quads[4];

	if (range.size <= 1 || is_sorted(range))
		return ;
	range_to_top(pair, range);
	if (range.size <= 5)
	{
		mysort_mini(pair, range);
		return ;
	}
	ft_memset(quads, 0, sizeof(quads));
	partition(pair, range, quads);
	mysort(pair, quads[0]);
	mysort(pair, quads[1]);
	mysort(pair, quads[2]);
	mysort(pair, quads[3]);
}

void	sort(t_cycle *a)
{
	t_cycle	*pair[2];

	pair[CYCLE_A] = a;
	pair[CYCLE_B] = new_cycle();
	if (!pair[CYCLE_B])
		handle_error(ERR_MSG);
	if (a->size == 3)
		mysort_tri_por(pair);
	else
		mysort(pair, node_range(a->bottom, a->top));
	while (!is_sorted(node_range(a->bottom, a->top)))
		adjust(pair, CMD_RA);
	free_cycle(pair[CYCLE_B]);
}

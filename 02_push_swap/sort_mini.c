/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:53:43 by jison             #+#    #+#             */
/*   Updated: 2023/01/16 14:51:44 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b2(int nums[], t_cycle *pair[], int size)
{
	if (inequ_chain(nums[2], nums[0], nums[1]))
	{
		adjust_n(pair, CMD_PB, 3);
		adjust(pair, CMD_RB);
	}
	else if (inequ_chain(nums[1], nums[2], nums[0]))
	{
		adjust_n(pair, CMD_PB, 3);
		adjust(pair, CMD_RRB);
	}
	else if (inequ_chain(nums[2], nums[1], nums[0]))
	{
		adjust_n(pair, CMD_PB, 3);
		adjust(pair, CMD_RB);
		if (size == 4)
			adjust(pair, CMD_SB);
	}
}

void	a_to_b(int nums[], t_cycle *pair[], int size)
{
	if (inequ_chain(nums[0], nums[1], nums[2]))
		adjust_n(pair, CMD_PB, 3);
	else if (inequ_chain(nums[0], nums[2], nums[1]))
	{
		adjust_n(pair, CMD_PB, 3);
		adjust(pair, CMD_SB);
	}
	else if (inequ_chain(nums[1], nums[0], nums[2]))
	{
		adjust(pair, CMD_SA);
		adjust_n(pair, CMD_PB, 3);
	}
	else
		a_to_b2(nums, pair, size);
}

void	b_to_a(t_cycle *pair[], int size)
{
	int	cnt;
	int	i;

	cnt = 0;
	while (cnt < size - 3 && pair[0]->top->value < pair[1]->top->value)
	{
		adjust(pair, CMD_RA);
		++cnt;
	}
	i = -1;
	while (++i < 3)
	{
		while (cnt > 0
			&& inequ_chain(
				pair[CYCLE_B]->top->value,
				pair[CYCLE_A]->bottom->value,
				pair[CYCLE_A]->top->value))
		{
			adjust(pair, CMD_RRA);
			--cnt;
		}
		adjust(pair, CMD_PA);
	}
	while (cnt--)
		adjust(pair, CMD_RRA);
}

void	mysort_five(int nums[], int sa_flag, t_cycle *pair[], int size)
{
	a_to_b(nums, pair, size);
	if (size == 5)
	{
		if (sa_flag && inequ_chain(nums[2], nums[1], nums[0]))
			adjust(pair, CMD_SS);
		else if (sa_flag)
			adjust(pair, CMD_SA);
		else if (inequ_chain(nums[2], nums[1], nums[0]))
			adjust(pair, CMD_SB);
	}
	b_to_a(pair, size);
}

void	mysort_mini(t_cycle *pair[], t_range range)
{
	int	nums[3];

	if (range.size == 2)
	{
		if (range.hi->value > range.lo->value)
			adjust(pair, CMD_SA);
	}
	else if (range.size == 3)
	{
		set_nums(nums, range);
		mysort_tri(nums, pair);
	}
	else
	{
		set_nums(nums, range);
		mysort_five(
			nums,
			range.lo->value < range.lo->next->value,
			pair,
			range.size
			);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini_por.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:58:06 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 16:02:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mysort_tri_por2(int nums[], t_cycle *pair[])
{
	if (nums[1] < nums[2] && nums[2] < nums[0])
	{
		adjust(pair, CMD_RA);
	}
	else if (nums[2] < nums[1] && nums[1] < nums[0])
	{
		adjust(pair, CMD_RA);
		adjust(pair, CMD_SA);
	}
}

void	mysort_tri_por(t_cycle *pair[])
{
	int	nums[3];

	set_nums(nums, node_range(pair[CYCLE_A]->bottom, pair[CYCLE_A]->top));
	if (nums[0] < nums[2] && nums[2] < nums[1])
	{
		adjust(pair, CMD_PB);
		adjust(pair, CMD_SA);
		adjust(pair, CMD_PA);
	}
	else if (nums[1] < nums[0] && nums[0] < nums[2])
		adjust(pair, CMD_SA);
	else if (nums[2] < nums[0] && nums[0] < nums[1])
	{
		adjust(pair, CMD_RRA);
	}
	else
		mysort_tri_por2(nums, pair);
}

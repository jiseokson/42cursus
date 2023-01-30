/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:51:25 by jison             #+#    #+#             */
/*   Updated: 2023/01/16 14:51:34 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inequ_chain(int a, int b, int c)
{
	return (a < b && b < c);
}

void	set_nums(int nums[], t_range range)
{
	nums[0] = range.hi->value;
	nums[1] = range.hi->prev->value;
	nums[2] = range.hi->prev->prev->value;
}

void	mysort_tri2(int nums[], t_cycle *pair[])
{
	if (nums[1] < nums[2] && nums[2] < nums[0])
	{
		adjust(pair, CMD_SA);
		adjust(pair, CMD_PB);
		adjust(pair, CMD_SA);
		adjust(pair, CMD_PA);
	}
	else if (nums[2] < nums[1] && nums[1] < nums[0])
	{
		adjust(pair, CMD_SA);
		adjust(pair, CMD_PB);
		adjust(pair, CMD_SA);
		adjust(pair, CMD_PA);
		adjust(pair, CMD_SA);
	}
}

void	mysort_tri(int nums[], t_cycle *pair[])
{
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
		adjust(pair, CMD_PB);
		adjust(pair, CMD_SA);
		adjust(pair, CMD_PB);
		adjust(pair, CMD_SB);
		adjust(pair, CMD_PA);
		adjust(pair, CMD_PA);
	}
	else
		mysort_tri2(nums, pair);
}

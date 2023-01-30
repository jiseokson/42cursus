/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:10:33 by jison             #+#    #+#             */
/*   Updated: 2023/01/04 16:42:39 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_swap(t_cycle *cycle)
{
	t_cycle_node	*temp1;
	t_cycle_node	*temp2;

	if (cycle->size <= 1)
		return (FALSE);
	temp1 = pop(cycle);
	temp2 = pop(cycle);
	push(cycle, temp1);
	push(cycle, temp2);
	return (TRUE);
}

int	cmd_sa(t_cycle *pair[])
{
	return (cmd_swap(pair[CYCLE_A]));
}

int	cmd_sb(t_cycle *pair[])
{
	return (cmd_swap(pair[CYCLE_B]));
}

int	cmd_ss(t_cycle *pair[])
{
	int	ret1;
	int	ret2;

	ret1 = cmd_swap(pair[CYCLE_A]);
	ret2 = cmd_swap(pair[CYCLE_B]);
	return (ret1 || ret2);
}

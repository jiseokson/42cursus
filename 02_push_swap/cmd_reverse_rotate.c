/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:15:49 by jison             #+#    #+#             */
/*   Updated: 2023/01/04 16:43:38 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_reverse_rotate(t_cycle *cycle)
{
	if (cycle->size <= 1)
		return (FALSE);
	cycle->bottom = cycle->bottom->next;
	cycle->top = cycle->top->next;
	return (TRUE);
}

int	cmd_rra(t_cycle *pair[])
{
	return (cmd_reverse_rotate(pair[CYCLE_A]));
}

int	cmd_rrb(t_cycle *pair[])
{
	return (cmd_reverse_rotate(pair[CYCLE_B]));
}

int	cmd_rrr(t_cycle *pair[])
{
	int	ret1;
	int	ret2;

	ret1 = cmd_reverse_rotate(pair[CYCLE_A]);
	ret2 = cmd_reverse_rotate(pair[CYCLE_B]);
	return (ret1 || ret2);
}

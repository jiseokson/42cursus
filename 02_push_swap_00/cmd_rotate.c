/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:13:06 by jison             #+#    #+#             */
/*   Updated: 2023/01/04 16:43:29 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_rotate(t_cycle *cycle)
{
	if (cycle->size <= 1)
		return (FALSE);
	cycle->bottom = cycle->bottom->prev;
	cycle->top = cycle->top->prev;
	return (TRUE);
}

int	cmd_ra(t_cycle *pair[])
{
	return (cmd_rotate(pair[CYCLE_A]));
}

int	cmd_rb(t_cycle *pair[])
{
	return (cmd_rotate(pair[CYCLE_B]));
}

int	cmd_rr(t_cycle *pair[])
{
	int	ret1;
	int	ret2;

	ret1 = cmd_rotate(pair[CYCLE_A]);
	ret2 = cmd_rotate(pair[CYCLE_B]);
	return (ret1 || ret2);
}

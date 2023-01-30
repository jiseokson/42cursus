/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:11:26 by jison             #+#    #+#             */
/*   Updated: 2023/01/02 11:26:03 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_push(t_cycle *from, t_cycle *to)
{
	if (from->size == 0)
		return (FALSE);
	push(to, pop(from));
	return (TRUE);
}

int	cmd_pa(t_cycle *pair[])
{
	return (cmd_push(pair[CYCLE_B], pair[CYCLE_A]));
}

int	cmd_pb(t_cycle *pair[])
{
	return (cmd_push(pair[CYCLE_A], pair[CYCLE_B]));
}

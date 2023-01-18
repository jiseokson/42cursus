/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:59:50 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 14:36:26 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cmd_id(const int cycle_id, const int cmd_type)
{
	return (cycle_id * 4 + cmd_type);
}

const char	*get_cmd_string(const int cmd_id)
{
	if (cmd_id == CMD_SA)
		return ("sa");
	else if (cmd_id == CMD_PA)
		return ("pa");
	else if (cmd_id == CMD_RA)
		return ("ra");
	else if (cmd_id == CMD_RRA)
		return ("rra");
	else if (cmd_id == CMD_SB)
		return ("sb");
	else if (cmd_id == CMD_PB)
		return ("pb");
	else if (cmd_id == CMD_RB)
		return ("rb");
	else if (cmd_id == CMD_RRB)
		return ("rrb");
	else if (cmd_id == CMD_SS)
		return ("ss");
	else if (cmd_id == CMD_RR)
		return ("rr");
	else if (cmd_id == CMD_RRR)
		return ("rrr");
	return ("NONE");
}

void	adjust(t_cycle *pair[], const int cmd_id)
{
	if (cmd_id == CMD_SA && !cmd_sa(pair))
		return ;
	else if (cmd_id == CMD_PA && !cmd_pa(pair))
		return ;
	else if (cmd_id == CMD_RA && !cmd_ra(pair))
		return ;
	else if (cmd_id == CMD_RRA && !cmd_rra(pair))
		return ;
	else if (cmd_id == CMD_SB && !cmd_sb(pair))
		return ;
	else if (cmd_id == CMD_PB && !cmd_pb(pair))
		return ;
	else if (cmd_id == CMD_RB && !cmd_rb(pair))
		return ;
	else if (cmd_id == CMD_RRB && !cmd_rrb(pair))
		return ;
	else if (cmd_id == CMD_SS && !cmd_ss(pair))
		return ;
	else if (cmd_id == CMD_RR && !cmd_rr(pair))
		return ;
	else if (cmd_id == CMD_RRR && !cmd_rrr(pair))
		return ;
	ft_fprint(STDOUT, get_cmd_string(cmd_id));
	ft_fprint(STDOUT, "\n");
}

void	adjust_n(t_cycle *pair[], const int cmd_id, int cnt)
{
	while (cnt--)
		adjust(pair, cmd_id);
}

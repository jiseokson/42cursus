/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:14:35 by jison             #+#    #+#             */
/*   Updated: 2023/01/17 15:20:25 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	cmd_string_to_id(char *line)
{
	if (!ft_memcmp(line, "sa\n", 3))
		return (CMD_SA);
	else if (!ft_memcmp(line, "pa\n", 3))
		return (CMD_PA);
	else if (!ft_memcmp(line, "ra\n", 3))
		return (CMD_RA);
	else if (!ft_memcmp(line, "rra\n", 3))
		return (CMD_RRA);
	else if (!ft_memcmp(line, "sb\n", 3))
		return (CMD_SB);
	else if (!ft_memcmp(line, "pb\n", 3))
		return (CMD_PB);
	else if (!ft_memcmp(line, "rb\n", 3))
		return (CMD_RB);
	else if (!ft_memcmp(line, "rrb\n", 3))
		return (CMD_RRB);
	else if (!ft_memcmp(line, "ss\n", 3))
		return (CMD_SS);
	else if (!ft_memcmp(line, "rr\n", 3))
		return (CMD_RR);
	else if (!ft_memcmp(line, "rrr\n", 3))
		return (CMD_RRR);
	handle_error(ERR_MSG);
	return (-1);
}

void	checker_adjust(t_cycle *pair[], const int cmd_id)
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
}

void	alloc_cycles(t_cycle *pair[], int ac, char **av)
{
	pair[CYCLE_A] = get_cycle(ac, av);
	pair[CYCLE_B] = new_cycle();
	if (!pair[CYCLE_A] || !pair[CYCLE_B])
	{
		free_cycle(pair[CYCLE_A]);
		free_cycle(pair[CYCLE_B]);
		handle_error(ERR_MSG);
	}
}

int	main(int ac, char **av)
{
	t_cycle	*pair[2];
	char	*line;

	if (ac == 1)
	{
		return (0);
	}
	alloc_cycles(pair, ac, av);
	while (1)
	{
		line = get_next_line(STDIN);
		if (!line)
			break ;
		checker_adjust(pair, cmd_string_to_id(line));
		free(line);
	}
	if (is_sorted(node_range(pair[CYCLE_A]->bottom, pair[CYCLE_A]->top))
		&& pair[CYCLE_B]->size == 0)
		ft_fprint(STDOUT, "OK\n");
	else
		ft_fprint(STDOUT, "KO\n");
	return (0);
}

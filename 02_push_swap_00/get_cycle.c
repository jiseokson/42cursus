/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:24:01 by jison             #+#    #+#             */
/*   Updated: 2023/01/11 20:39:11 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arg_list(char **arg_list)
{
	int	size;

	if (!arg_list)
		return ;
	size = 0;
	while (arg_list[size])
		++size;
	while (size--)
		free(arg_list[size]);
	free(arg_list);
}

void	handle_get_cycle_error(char **arg_list, t_cycle *a)
{
	free_arg_list(arg_list);
	free_cycle(a);
	handle_error(ERR_MSG);
}

void	iterate_arg_list(char **arg_list, t_cycle *a)
{
	int				i;
	long			arg;
	char			*endptr;
	t_cycle_node	*temp;

	i = 0;
	while (arg_list[i])
	{
		arg = ft_atol(arg_list[i], &endptr);
		if (!(*endptr == '\0' && INT_MIN <= arg && arg <= INT_MAX))
			handle_get_cycle_error(arg_list, a);
		temp = new_cycle_node(arg);
		if (!temp)
			handle_get_cycle_error(arg_list, a);
		push(a, temp);
		rotate(a);
		++i;
	}
}

int	check_double_element(t_cycle *cycle)
{
	int				size;
	t_cycle_node	*i;
	t_cycle_node	*j;

	if (cycle->size <= 1)
		return (FALSE);
	size = cycle->size;
	i = cycle->bottom;
	while (size--)
	{
		j = i->next;
		while (j != cycle->bottom)
		{
			if (i->value == j->value)
				return (TRUE);
			j = j->next;
		}
		i = i->next;
	}
	return (FALSE);
}

t_cycle	*get_cycle(int ac, char **av)
{
	char	**arg_list;
	t_cycle	*a;

	(void)ac;
	arg_list = NULL;
	a = new_cycle();
	if (!a)
		handle_get_cycle_error(arg_list, a);
	while (*(++av))
	{
		arg_list = ft_split(*av);
		if (!arg_list || *arg_list == 0)
			handle_get_cycle_error(arg_list, a);
		iterate_arg_list(arg_list, a);
		free_arg_list(arg_list);
	}
	if (check_double_element(a))
		handle_get_cycle_error(NULL, a);
	return (a);
}

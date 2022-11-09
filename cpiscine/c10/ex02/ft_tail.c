/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:14:28 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 23:29:42 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include "tail.h"
#include "io.h"
#include "ft_print.h"
#include "ft_string.h"

int	parse_offset(char *arg)
{
	int	offset;

	offset = 0;
	while (*arg == '0')
		++arg;
	while (*arg)
	{
		offset = offset * 10 + *arg - '0';
		++arg;
	}
	return (offset);
}

int	is_valid_arg(char *arg)
{
	while (*arg)
	{
		if (!('0' <= *arg && *arg <= '9'))
			return (0);
		++arg;
	}
	return (1);
}

int	get_option(int ac, char **av, char *option, char **arg)
{
	if (2 < ac && !ft_strcmp(av[1], option))
	{
		*arg = av[2];
		return (1);
	}
	else if (ac == 2 && !ft_strcmp(av[1], option))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	*program_name;
	char	*arg;
	int		offset;

	program_name = basename(av[0]);
	arg = 0;
	if (!get_option(ac, av, "-c", &arg))
	{
		ft_print_usage();
		return (1);
	}
	if (arg && !is_valid_arg(arg))
	{
		ft_print_offset_error(program_name, arg);
		return (1);
	}
	else if (arg)
		offset = parse_offset(arg);
	else
		offset = -1;
	if (offset != -1)
		run(program_name, ac - 3, av + 3, offset);
	else
		run(program_name, ac - 1, av + 1, offset);
	return (0);
}

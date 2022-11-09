/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:08:47 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 21:28:45 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "rush.h"
#include "dict_list.h"
#include "ft_string.h"
#include "ft_print.h"
#include "parse_dict.h"

int	all_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		++str;
	}
	return (1);
}

int	do_rush(t_dict_list *dict_list, char *arg, char *path)
{
	dict_list = new_dict_list();
	if (! parse_dict(dict_list, path))
	{
		ft_fprint(2, "Dict Error\n");
		free_dict_list(dict_list);
		return (1);
	}
	if (! is_valid_arg(dict_list, arg))
	{
		free_dict_list(dict_list);
		return (1);
	}
	arg = rush_preprocess(arg);
	if (all_zero(arg))
		ft_fprint(1, search(dict_list, "0")->value);
	else
		rush(dict_list, arg, 0);
	ft_fprint(1, "\n");
	free(arg);
	free_dict_list(dict_list);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict_list	*dict_list;
	char		*arg;
	char		*path;

	if (argc == 3)
	{
		path = argv[1];
		arg = argv[2];
	}
	else if (argc == 2)
	{
		path = "numbers.dict";
		arg = argv[1];
	}
	else
		return (1);
	dict_list = 0;
	return (do_rush(dict_list, arg, path));
}

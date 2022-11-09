/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:21:20 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 19:45:33 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "dict_list.h"
#include "ft_print.h"
#include "ft_string.h"

t_dict_node	*su(t_dict_list *dict_list, int key)
{
	return (search_by_uint(dict_list, key));
}

void	print_100(t_dict_list *dict_list, char *str)
{
	if (ft_strlen(str) > 2 && str[2] != '0')
	{
		if (is_head_printed(str, 3, -1))
			ft_fprint(1, " ");
		ft_fprint(1, search_by_uint(dict_list, str[2] - '0')->value);
		ft_fprint(1, " ");
		ft_fprint(1, search_by_uint(dict_list, 100)->value);
	}
}

void	print_10_2(t_dict_list *dict_list, char *str)
{
	if (is_head_printed(str, 2, -1))
		ft_fprint(1, " ");
	ft_fprint(1, search_by_uint(dict_list, (str[1] - '0') * 10)->value);
	ft_fprint(1, " ");
	ft_fprint(1, search_by_uint(dict_list, str[0] - '0')->value);
}

void	print_10(t_dict_list *dict_list, char *str)
{
	char	*temp;

	if (ft_strlen(str) > 1 && str[1] != '0' && str[0] == '0')
	{
		if (is_head_printed(str, 2, -1))
			ft_fprint(1, " ");
		ft_fprint(1, search_by_uint(dict_list, (str[1] - '0') * 10)->value);
	}
	else if (ft_strlen(str) > 1 && str[1] == '1' && str[0] != '0')
	{
		if (is_head_printed(str, 2, -1))
			ft_fprint(1, " ");
		temp = su(dict_list, 10 * str[1] + str[0] - 11 * '0')->value;
		ft_fprint(1, temp);
	}
	else if (ft_strlen(str) > 1 && str[1] > '1' && str[0] != '0')
		print_10_2(dict_list, str);
	else if (ft_strlen(str) > 0 && str[0] != '0')
	{
		if (is_head_printed(str, 1, -1))
			ft_fprint(1, " ");
		ft_fprint(1, search_by_uint(dict_list, str[0] - '0')->value);
	}
}

void	print_block_unit(t_dict_list *dict_list, char *str, int block_index)
{
	if (block_index > 0 && is_head_printed(str, 0, 3))
	{
		ft_fprint(1, " ");
		ft_fprint(1, search_by_block_index(dict_list, block_index)->value);
	}
}

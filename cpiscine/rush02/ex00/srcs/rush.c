/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:43:50 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 19:33:05 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"
#include "dict_list.h"
#include "ft_print.h"
#include "ft_string.h"

int	is_head_printed(char *str, int i, int n)
{
	if (ft_strlen(str) <= i)
		return (0);
	str += i;
	if (n != -1)
	{
		while (*str && n--)
		{
			if (*str != '0')
				return (1);
			++str;
		}
	}
	else
	{
		while (*str)
		{
			if (*str != '0')
				return (1);
			++str;
		}
	}
	return (0);
}

int	is_numeric(char *str)
{
	while (*str)
	{
		if (! ('0' <= *str && *str <= '9'))
		{
			ft_fprint(2, "Error\n");
			return (0);
		}
		++str;
	}
	return (1);
}

int	is_valid_arg(t_dict_list *dict_list, char *arg)
{
	char	*temp;
	int		block_index;

	if (! is_numeric(arg))
		return (0);
	temp = arg;
	while (*temp == '0')
		++temp;
	block_index = (ft_strlen(temp) - 1) / 3;
	while (block_index > 0)
	{
		if (! search_by_block_index(dict_list, block_index))
		{
			ft_fprint(2, "Dict Error\n");
			return (0);
		}
		--block_index;
	}
	return (1);
}

char	*rush_preprocess(char *arg)
{
	char	*ret;

	while (*arg == '0')
		++arg;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (! ret)
		return (0);
	ret[0] = '\0';
	ft_strcpy(ret, arg);
	ft_strrev(ret);
	return (ret);
}

void	rush(t_dict_list *dict_list, char *str, int block_index)
{
	if (ft_strlen(str) > 3)
		rush(dict_list, str + 3, block_index + 1);
	print_100(dict_list, str);
	print_10(dict_list, str);
	print_block_unit(dict_list, str, block_index);
}

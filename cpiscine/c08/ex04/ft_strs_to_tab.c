/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:21 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 23:02:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_strlen(char *str)
{
	long long	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	temp;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (! ret)
		return (0);
	i = -1;
	while (++i < ac)
	{
		temp.size = ft_strlen(av[i]);
		temp.str = av[i];
		temp.copy = ft_strdup(av[i]);
		ret[i] = temp;
	}
	temp.size = 0;
	temp.str = 0;
	temp.copy = 0;
	ret[i] = temp;
	return (ret);
}

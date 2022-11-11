/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:48:15 by jison             #+#    #+#             */
/*   Updated: 2022/11/10 21:00:06 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_n_len(int n)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	if (n < 0)
		++ret;
	while (n != 0)
	{
		++ret;
		n /= 10;
	}
	return (ret);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		ret_len;
	char	*ret;

	ret_len = get_n_len(n);
	ret = (char *)malloc((ret_len + 1) * sizeof(char));
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	else
	{
		if (n < 0)
			ret[0] = '-';
		i = ret_len - 1;
		while (n != 0)
		{
			ret[i] = ft_abs(n % 10) + '0';
			n /= 10;
			--i;
		}
	}
	ret[ret_len] = '\0';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:14:49 by jison             #+#    #+#             */
/*   Updated: 2022/11/12 17:37:56 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	char	*spaces;

	spaces = "\t\n\v\f\r ";
	while (*spaces && *spaces != c)
		++spaces;
	return (*spaces == c);
}

static int	ft_atol_check_flow(long n, long sign)
{
	if ((sign > 0L && n < 0L) || (sign < 0L && n > 0L))
		return (1);
	return (0);
}

static long	ft_atol_flow_case(long sign)
{
	if (sign > 0L)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

static long	ft_atol(const char *str)
{
	long	sign;
	long	ret;

	ret = 0L;
	sign = 1L;
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '+')
	{
		++str;
	}
	else if (*str == '-')
	{
		++str;
		sign = -1L;
	}
	while (*str && ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str - '0');
		if (ft_atol_check_flow(ret, sign))
			return (ft_atol_flow_case(sign));
		++str;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}

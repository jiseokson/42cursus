/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:51:19 by jison             #+#    #+#             */
/*   Updated: 2022/11/23 14:28:05 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int	is_space(char c)
{
	char	*spaces;

	spaces = "\t\n\v\f\r ";
	while (*spaces && *spaces != c)
		++spaces;
	return (*spaces == c);
}

int	ft_atol_check_flow(long n, long sign)
{
	if ((sign > 0L && n < 0L) || (sign < 0L && n > 0L))
		return (1);
	return (0);
}

long	ft_atol_flow_case(long sign)
{
	if (sign > 0L)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

long	ft_strtol(const char *str, const char **endptr)
{
	long	sign;
	long	ret;

	ret = 0L;
	sign = 1L;
	while (*str && is_space(*str))
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
	while (*str && is_digit(*str))
	{
		ret = ret * 10 + sign * (*str - '0');
		if (ft_atol_check_flow(ret, sign))
			return (ft_atol_flow_case(sign));
		++str;
	}
	*endptr = str;
	return (ret);
}

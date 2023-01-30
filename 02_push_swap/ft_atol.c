/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:13:40 by jison             #+#    #+#             */
/*   Updated: 2022/12/12 16:36:01 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atol_check_flow(long n, long sign)
{
	if ((sign > 0L && n < 0L) || (sign < 0L && n > 0L))
		return (1);
	return (0);
}

long	atol_flow_case(long sign)
{
	if (sign > 0L)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

long	ft_atol(const char *str, char **endptr)
{
	long	sign;
	long	ret;

	ret = 0L;
	sign = 1L;
	while (*str && is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		++str;
		sign = -1L;
	}
	while (*str && is_digit(*str))
	{
		ret = ret * 10 + sign * (*str - '0');
		if (atol_check_flow(ret, sign))
			return (atol_flow_case(sign));
		++str;
	}
	if (endptr)
		*endptr = (char *)str;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:21:21 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 11:22:34 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (! is_numeric(*str))
			return (0);
		++str;
	}
	return (1);
}

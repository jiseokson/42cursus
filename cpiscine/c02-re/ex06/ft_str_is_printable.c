/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:10:00 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 22:18:00 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	return (32 <= c && c <= 126);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (! is_printable(*str))
			return (0);
		++str;
	}
	return (1);
}

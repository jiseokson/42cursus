/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:23:11 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 18:43:26 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (! is_lowercase(*str))
			return (0);
		++str;
	}
	return (1);
}

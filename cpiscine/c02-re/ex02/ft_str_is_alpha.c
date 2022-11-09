/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:16:11 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 16:35:38 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_char_alpha(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c & c <= 'Z'));
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (! is_char_alpha(*str))
			return (0);
		++str;
	}
	return (1);
}

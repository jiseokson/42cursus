/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:15:13 by jison             #+#    #+#             */
/*   Updated: 2022/12/28 20:06:28 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(const char c)
{
	char	*spaces;

	if (c == '\0')
		return (FALSE);
	spaces = "\t\n\v\f\r ";
	while (*spaces && *spaces != c)
		++spaces;
	return (*spaces == c);
}

int	is_digit(const char c)
{
	return ('0' <= c && c <= '9');
}

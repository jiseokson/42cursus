/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:14:34 by jison             #+#    #+#             */
/*   Updated: 2022/10/13 20:37:26 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c);

int	count_word(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			++i;
		if (str[i])
			++ret;
		while (str[i] && ! is_space(str[i]))
			++i;
	}
	return (ret);
}

void	set_word_range(char *str, int *lo, int *hi)
{
	while (str[*hi] && is_space(str[*hi]))
		++(*hi);
	if (str[*hi])
		*lo = *hi;
	while (str[*hi] && ! is_space(str[*hi]))
		++(*hi);
	--(*hi);
}

int	get_operator_id(char *str)
{
	int	lo;
	int	hi;

	if (count_word(str) != 1)
		return (5);
	lo = 0;
	hi = 0;
	set_word_range(str, &lo, &hi);
	if (lo < hi)
		return (5);
	if (str[lo] == '+')
		return (0);
	if (str[lo] == '-')
		return (1);
	if (str[lo] == '*')
		return (2);
	if (str[lo] == '/')
		return (3);
	if (str[lo] == '%')
		return (4);
	return (5);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:29:18 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 15:15:52 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	char	*space_class;

	space_class = "\t\n\v\f\r ";
	while (*space_class)
	{
		if (c == *space_class)
			return (1);
		++space_class;
	}
	return (0);
}

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	my_atoi(char *str)
{
	int	ret;

	if (*str == '-')
		return (-my_atoi(str + 1));
	if (*str == '+')
		return (my_atoi(str + 1));
	ret = 0;
	while (is_digit(*str))
	{
		ret *= 10;
		ret += *str - '0';
		++str;
	}
	return (ret);
}

int	ft_atoi(char *str)
{
	while (is_space(*str))
		++str;
	return (my_atoi(str));
}

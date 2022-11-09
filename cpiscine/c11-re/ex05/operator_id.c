/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:14:34 by jison             #+#    #+#             */
/*   Updated: 2022/10/15 12:41:21 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	get_operator_id(char *str)
{
	if (! ft_strcmp(str, "+"))
		return (0);
	if (! ft_strcmp(str, "-"))
		return (1);
	if (! ft_strcmp(str, "*"))
		return (2);
	if (! ft_strcmp(str, "/"))
		return (3);
	if (! ft_strcmp(str, "%"))
		return (4);
	return (5);
}

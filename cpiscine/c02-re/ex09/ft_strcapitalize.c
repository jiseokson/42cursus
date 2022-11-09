/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:32:23 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 22:48:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	upper(char *c)
{
	if ('a' <= *c && *c <= 'z')
		*c = *c - 'a' + 'A';
}

void	lower(char *c)
{
	if ('A' <= *c && *c <= 'Z')
		*c = *c - 'A' + 'a';
}

int	is_alphanumeric(char c)
{
	return (('a' <= c && c <= 'z') || \
	('A' <= c && c <= 'Z') || \
	('0' <= c && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			upper(&str[i]);
			++i;
			while (is_alphanumeric(str[i]))
			{
				lower(&str[i]);
				++i;
			}
		}
		else
			++i;
	}
	return (str);
}

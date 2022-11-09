/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:32:23 by jison             #+#    #+#             */
/*   Updated: 2022/10/04 17:06:28 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	upper(char *c)
{
	if ('a' <= *c && *c <= 'z')
		*c = *c - 'a' + 'A';
}

int	is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	is_alpha(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	is_alphanumeric(char c)
{
	return (is_numeric(c) || is_alpha(c));
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
			while (is_alphanumeric(str[i]))
				++i;
		}
		else
			++i;
	}
	return (str);
}

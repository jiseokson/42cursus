/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:03:42 by jison             #+#    #+#             */
/*   Updated: 2022/10/13 21:08:08 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	**i;
	char	**j;

	i = tab;
	while (*i)
	{
		j = i;
		while (j != tab && cmp(*(j - 1), *j))
		{
			swap(j - 1, j);
			--j;
		}
		++i;
	}
}

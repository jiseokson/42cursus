/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:47:18 by jison             #+#    #+#             */
/*   Updated: 2022/10/10 14:20:34 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(char **argv, int lo, int hi)
{
	int	i;
	int	j;

	i = 0;
	while (lo + i <= hi)
	{
		j = lo + i;
		while (j > lo && my_strcmp(argv[j - 1], argv[j]) > 0)
		{
			swap(&argv[j - 1], &argv[j]);
			--j;
		}
		++i;
	}
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		++i;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	sort(argv, 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		putstr(argv[i]);
		++i;
	}
	return (0);
}

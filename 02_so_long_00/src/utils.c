/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:54:13 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 19:22:18 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	in_range(int width, int height, int x, int y)
{
	return (0 <= x && x < width && 0 <= y && y < height);
}

char	*ft_basename(char *path)
{
	int	has_dot;

	has_dot = 0;
	while (*path)
	{
		if (*path == '.')
			has_dot = 1;
		++path;
	}
	if (!has_dot)
		return (NULL);
	while (*path != '.')
		--path;
	return (path + 1);
}

void	ft_free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

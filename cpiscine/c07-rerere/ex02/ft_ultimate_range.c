/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:31:24 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 12:45:25 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	i;
	long long	size;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = (long long)max - (long long)min;
	*range = (int *)malloc(sizeof(int) * size);
	if (! range)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		++i;
	}
	return (size);
}

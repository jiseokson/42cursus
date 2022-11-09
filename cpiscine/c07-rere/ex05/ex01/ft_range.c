/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:45:07 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 12:43:36 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*ret;
	long long	i;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * ((long long)max - (long long)min));
	if (! ret)
		return (0);
	i = 0;
	while (i + min < max)
	{
		ret[i] = min + i;
		++i;
	}
	return (ret);
}

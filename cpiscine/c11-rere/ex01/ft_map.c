/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:17:20 by jison             #+#    #+#             */
/*   Updated: 2022/10/13 18:25:42 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	ret = (int *)malloc(sizeof(int) * length);
	if (! ret)
		return (0);
	i = -1;
	while (++i < length)
		ret[i] = f(tab[i]);
	return (ret);
}

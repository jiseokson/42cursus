/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:42:58 by jison             #+#    #+#             */
/*   Updated: 2022/10/15 12:48:28 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			ret = 0;
			break;
		}
	}
	if (! ret)
	{
		i = -1;
		ret = 1;
		while (++i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
			{
				ret = 0;
				break;
			}
		}
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:42:58 by jison             #+#    #+#             */
/*   Updated: 2022/10/15 18:06:49 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort2(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			return (ft_is_sort2(tab, length, f));
	return (1);
}

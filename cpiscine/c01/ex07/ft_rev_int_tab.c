/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:21:29 by jison             #+#    #+#             */
/*   Updated: 2022/10/01 22:24:39 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	lo;
	int	hi;
	int	temp;

	lo = 0;
	hi = size - 1;
	while (lo < hi)
	{
		temp = tab[lo];
		tab[lo] = tab[hi];
		tab[hi] = temp;
		++lo;
		--hi;
	}
}

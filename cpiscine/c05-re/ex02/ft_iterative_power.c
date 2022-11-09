/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:30:37 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 21:06:14 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	ret = nb;
	i = 0;
	while (i < power - 1)
	{
		ret *= nb;
		++i;
	}
	return (ret);
}

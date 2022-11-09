/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:42:51 by jison             #+#    #+#             */
/*   Updated: 2022/10/08 14:23:06 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	factor;

	if (nb <= 1)
		return (0);
	factor = 2;
	while (factor * factor <= nb)
	{
		if (nb % factor == 0)
			return (0);
		++factor;
	}
	return (1);
}

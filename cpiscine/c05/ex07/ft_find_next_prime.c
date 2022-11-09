/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:44:16 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 21:06:59 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int n)
{
	int	factor;

	if (n <= 1)
		return (0);
	factor = 2;
	while (factor * factor <= n)
	{
		if (n % factor == 0)
			return (0);
		++factor;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	ret;

	ret = nb;
	while (! is_prime(ret))
		++ret;
	return (ret);
}

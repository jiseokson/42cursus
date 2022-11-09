/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:06:36 by jison             #+#    #+#             */
/*   Updated: 2022/10/13 20:41:30 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sum(int n1, int n2);
int	sub(int n1, int n2);
int	mul(int n1, int n2);
int	div(int n1, int n2);
int	mod(int n1, int n2);

int	inv(int n1, int n2)
{
	(void)n1;
	(void)n2;
	return (0);
}

int	eval(int n1, int n2, int operator_id)
{
	int	(*operator[6])(int, int);

	operator[0] = sum;
	operator[1] = sub;
	operator[2] = mul;
	operator[3] = div;
	operator[4] = mod;
	operator[5] = inv;
	return (operator[operator_id](n1, n2));
}

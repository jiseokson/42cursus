/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:41:15 by jison             #+#    #+#             */
/*   Updated: 2022/10/09 20:52:29 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_width(void);

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	putnum(int n)
{
	char	*dec_digit;

	if (n == 0)
		return ;
	dec_digit = "0123456789";
	putnum(n / 10);
	write(1, dec_digit + n % 10, 1);
}

void	print_map(int **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < get_width())
	{
		j = -1;
		while (++j < get_width())
		{
			putnum(map[i][j]);
			if (j < get_width() - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

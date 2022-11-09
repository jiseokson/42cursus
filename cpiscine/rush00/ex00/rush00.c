/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujlim <sujlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:59:04 by sujlim            #+#    #+#             */
/*   Updated: 2022/10/01 20:53:25 by sujlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char c);

int	get_area_id(int x, int y, int i, int j)
{
	if (1 < i && i < x && 1 < j && j < y)
		return (0);
	else if (i == 1 && j == 1)
		return (1);
	else if (i == x && j == 1)
		return (2);
	else if (i == 1 && j == y)
		return (3);
	else if (i == x && j == y)
		return (4);
	else if (j == 1 || j == y)
		return (5);
	else
		return (6);
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	*chs;

	chs = " oooo-|";
	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			ft_putchar(chs[get_area_id(x, y, i, j)]);
			++i;
		}
		ft_putchar('\n');
		++j;
	}
}

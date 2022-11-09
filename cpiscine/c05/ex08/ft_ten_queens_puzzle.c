/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:46:23 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 21:07:44 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	in_range(int i, int j)
{
	return (0 <= i && i < 10 && 0 <= j && j < 10);
}

void	print_board(int *board)
{
	int		i;
	char	*dec_digit;

	i = -1;
	dec_digit = "0123456789";
	while (++i < 10)
		write(1, dec_digit + board[i], 1);
	write(1, "\n", 1);
}

int	can_put(int *board, int i, int j)
{
	int	x;
	int	d;

	x = i - 1;
	while (0 <= x)
	{
		if (board[x] == j)
			return (0);
		--x;
	}
	d = 1;
	while (i - d >= 0)
	{
		if (in_range(i - d, j - d) && board[i - d] == j - d)
			return (0);
		if (in_range(i - d, j + d) && board[i - d] == j + d)
			return (0);
		++d;
	}
	return (1);
}

int	ten_queens(int *board, int i)
{
	int	j;
	int	ret;

	if (i == 10)
	{
		print_board(board);
		return (1);
	}
	j = -1;
	ret = 0;
	while (++j < 10)
	{
		if (! can_put(board, i, j))
			continue ;
		board[i] = j;
		ret += ten_queens(board, i + 1);
		board[i] = -1;
	}
	return (ret);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;

	i = 0;
	while (i < 10)
		board[i++] = -1;
	return (ten_queens(board, 0));
}

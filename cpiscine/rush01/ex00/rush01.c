/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:41:04 by jison             #+#    #+#             */
/*   Updated: 2022/10/09 22:46:37 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_width(void);
void	print_map(int **map);

int	count(int **map, int dir, int y, int x)
{
	char	*dy;
	char	*dx;
	int		ret;
	int		min;

	dy = "2011";
	dx = "1120";
	ret = 0;
	min = 0;
	while (0 <= y && y < get_width() && 0 <= x && x < get_width())
	{
		if (min < map[y][x])
		{
			min = map[y][x];
			++ret;
		}
		y += dy[dir] - '1';
		x += dx[dir] - '1';
	}
	return (ret);
}

int	can_put(int **map, int y, int x, int n)
{
	int	i;

	i = -1;
	while (++i < get_width())
	{
		if (i != y && map[i][x] != 0 && map[i][x] == n)
			return (0);
		if (i != x && map[y][i] != 0 && map[y][i] == n)
			return (0);
	}
	return (1);
}

int	check(int **map, int *puzzle)
{
	int	i;

	i = -1;
	while (++i < get_width())
	{
		if (count(map, 0, 0, i) != puzzle[i])
			return (0);
		if (count(map, 1, get_width() - 1, i) != puzzle[get_width() + i])
			return (0);
		if (count(map, 2, i, 0) != puzzle[get_width() * 2 + i])
			return (0);
		if (count(map, 3, i, get_width() - 1) != puzzle[get_width() * 3 + i])
			return (0);
	}
	return (1);
}

int	rush(int **map, int *puzzle, int y, int x)
{
	int	i;
	int	ny;
	int	nx;

	if (y == get_width())
	{
		if (! check(map, puzzle))
			return (0);
		print_map(map);
		return (1);
	}
	i = 0;
	while (++i <= get_width())
	{
		if (! can_put(map, y, x, i))
			continue ;
		map[y][x] = i;
		ny = (y * get_width() + x + 1) / get_width();
		nx = (y * get_width() + x + 1) % get_width();
		if (rush(map, puzzle, ny, nx))
			return (1);
		map[y][x] = 0;
	}
	return (0);
}

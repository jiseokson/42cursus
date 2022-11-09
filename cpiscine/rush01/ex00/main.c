/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:42:17 by jison             #+#    #+#             */
/*   Updated: 2022/10/09 22:52:59 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_width(void);
void	putstr(char *str);
int		print_error(char *str, int exit_code);
int		split(char *str, int *puzzle);
int		rush(int **map, int *puzzle, int y, int x);

int	**alloc_empty_map(void)
{
	int	i;
	int	j;
	int	**ret;

	ret = (int **)malloc(sizeof(int *) * get_width());
	if (! ret)
		return (0);
	i = -1;
	while (++i < get_width())
	{
		ret[i] = (int *)malloc(sizeof(int) * get_width());
		j = -1;
		while (++j < get_width())
			ret[i][j] = 0;
	}
	return (ret);
}

int	alloc_resources(int ***map, int **puzzle)
{
	*map = alloc_empty_map();
	*puzzle = (int *)malloc(sizeof(int) * get_width());
	if (!map || !puzzle)
		return (0);
	return (1);
}

void	free_resources(int **map, int *puzzle)
{
	int	i;

	i = -1;
	while (++i < get_width())
		free(map[i]);
	free(map);
	free(puzzle);
}

int	main(int argc, char **argv)
{
	int	**map;
	int	*puzzle;

	map = 0;
	puzzle = 0;
	if (argc == 1)
		return (print_error("Usage: rush \"<int int ... int>\"\n", 0));
	if (argc != 2)
		return (print_error("Error: two program factors must be entered\n", 1));
	if (! alloc_resources(&map, &puzzle))
		return (print_error("Error: allocation error\n", 1));
	if (! split(argv[1], puzzle))
	{
		free_resources(map, puzzle);
		return (1);
	}
	if (! rush(map, puzzle, 0, 0))
	{
		free_resources(map, puzzle);
		return (print_error("Error: no answer exist\n", 1));
	}
	free_resources(map, puzzle);
	return (0);
}

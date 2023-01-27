/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:47:54 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 12:09:46 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	log_map_file_validity(char **lines, char *message)
{
	ft_printf(
		"%s: Map file parsing error: %s\n",
		TITLE,
		message
		);
	ft_free_split(lines);
	exit(1);
}

void	log_map_validity(t_map map, char *message)
{
	ft_printf(
		"%s: Map error: %s\n",
		TITLE,
		message
		);
	free(map.map);
	exit(1);
}

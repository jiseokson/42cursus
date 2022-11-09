/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:00:08 by jison             #+#    #+#             */
/*   Updated: 2022/10/19 19:41:24 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_print.h"

void	ft_fprint(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_fprint_char(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_print_file_name(char *path)
{
	ft_fprint(1, "==> ");
	ft_fprint(1, path);
	ft_fprint(1, " <==\n");
}
